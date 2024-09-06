struct Treap {
	int sz, val, pri, tag;
	Treap *l , *r;
	Treap(int _val){
		val=_val; sz=1;
		pri=rand(); l=r=NULL; tag=0;
	}
};
int Size(Treap *a) {return a?a->sz:0;}
void pull(Treap *a) {
	a->sz = Size(a->l) + Size(a->r) + 1;
}
//val of a is always bigger than val of b
Treap* merge(Treap *a ,Treap *b) {
	if(!a || !b) return a ? a : b;
	if(a->pri>b->pri) {
		a->r = merge(a->r ,b);
		pull(a);
		return a;
	} else {
		b->l = merge( a , b->l );
		pull(b);
		return b;
	}
}
// a<k, b>=k
void split(Treap *t, int k, Treap*&a, Treap*&b){
	if(!t) {a=b=NULL; return; }
	if(k <= t->val) {
		b = t;
		split(t->l, k, a, b->l);
		pull(b);
	}
	else {
		a = t;
		split(t->r,k,a->r,b);
		pull(a);
    }	
}
Treap* add(Treap *t, int v) {
    Treap *val = new Treap(v);
    Treap *l = NULL, *r = NULL;
    split(t, v, l, r);
    return merge(merge(l, val), r);
}
Treap* del(Treap *t, int v) {
    Treap *l, *mid, *r, *temp;
    split(t, v, l, temp);
    split(temp, v+1, mid, r);
    return merge(l, r);
}
// base 1
int position(Treap *t, int p) {
    if(Size(t->l)+1==p) return t->val;
    if(Size(t->l)<p) return position(t->r, p-Size(t->l)-1);
    else return position(t->l, p);
}
//num of >= k
int query(Treap *t, int k) {
    if(!t) return 0;
    if(t->val==k) return Size(t->l)+1;
    if(t->val>k) return query(t->l, k);
    return Size(t->l)+1+query(t->r, k);
}