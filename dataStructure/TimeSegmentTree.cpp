#include <bits/stdc++.h>
#define int long long int
using namespace std;
int n, q;
struct node{
    int val;
    node *l, *r;
    node(int v) {val=v; l=r=nullptr;}
    node() {val=0; l=r=nullptr;}
};
vector<node*> timing;
node* build(int s, int e) {
    node *ret = new node();
    if(s==e) return ret;
    int mid = (s+e)>>1;
    ret->l = build(s, mid);
    ret->r = build(mid+1, e);
    ret->val = ret->l->val + ret->r->val;
    return ret;
}
node* update(node* pre, int s, int e, int pos, int v) {
    node *ret = new node();
    if(s==e) {ret->val=pre->val+v; return ret;}
    int mid = (s+e)>>1;
    if(pos<=mid) {
        ret->l = update(pre->l, s, mid, pos, v);
        ret->r = pre->r;
    } else {
        ret->r = update(pre->r, mid+1, e, pos, v);
        ret->l = pre->l;
    }
    ret->val = ret->l->val + ret->r->val;
    return ret;
}
void add(int pos, int v) {
    timing.push_back(update(timing.back(), 1, n, pos, v));
}
int que(node* pre, node* now, int l, int r, int k) {
    if(l==r) return r;
    int mid = (l+r)>>1;
    int diff = now->l->val - pre->l->val;
    //printf("now %d~%d  diff %d\n", l, r, diff);
    if(diff>=k) return que(pre->l, now->l, l, mid, k);
    else return que(pre->r, now->r, mid+1, r, k-diff);
    return -1;
}
int query(int l, int r, int k) {
    l--;
    return que(timing[l], timing[r], 1, n, k);
}
int num[100005];
vector<int> sor;
map<int, int> mp;
signed main() {
    cin>>n>>q; 
    timing.push_back(build(1, n));
    for(int i=0,a ; i<n ; i++) {
        cin>>a; num[i] = a; sor.push_back(a);
    }
    // add: 1 1 1 2 1
    // num: 3 3 3 4 3
    // sor: 3 4
    sort(sor.begin(), sor.end());
    sor.erase(unique(sor.begin(), sor.end()), sor.end());
    for(int i=0 ; i<n ;i++) {
        int pos = lower_bound(sor.begin(), sor.end(), num[i]) - sor.begin() + 1;
        //printf("mp[%d] = %d\n", pos, num[i]);
        mp[pos] = num[i];
        num[i] = pos;
        add(num[i], 1);
    }
    while(q--) {
        int a, b, c; cin>>a>>b>>c;
        cout<<mp[query(a, b, c)]<<endl;
    }
}