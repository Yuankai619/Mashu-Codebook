struct seg {
    // 加值持久化線段樹
    struct Node {
        int val;
        Node *l, *r;
    };
    vector<Node*> version;
    void pull(Node* node) {
        node->val = node->l->val+node->r->val;
    }
    Node* build(int l,int r) {
        Node* node=new Node;
        if(l==r) {
           node->val = 0;  //初始值
           return node;
        }
        int mid = (l+r)/2;
        node->l = build(l,mid);
        node->r = build(mid+1,r);
        pull(node);
        return node;
    }
    Node* update(Node* cur,int l,int r,int pos,int v) {
        Node* node=new Node;
        if(l==r){
           node->val=v;
           return node;
        }
        int mid=(l+r)/2;
        if(pos<=mid) {
            node->l=update(cur->l,l,mid,pos,v);
            node->r=cur->r;
        } else {
            node->l=cur->l;
            node->r=update(cur->r,mid+1,r,pos,v);
        }
        pull(node);
        return node;
    }
    int query(Node* cur,int s, int e, int ql, int qr){
        if(ql<=s && e<=qr) return cur->val;
        int ans = 0;
        int mid = (s+e)/2;
        if(ql<=mid) ans += query(cur->l, s, mid, ql, qr);
        if(mid+1<=qr) ans += query(cur->r, mid+1, e, ql, qr);
        return ans;
    }
} tree;