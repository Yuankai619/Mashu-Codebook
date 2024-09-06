// tree.init(區間大小 0~n)
// tree.add(ql, qr, val) 區間加值
// tree.query(ql, qr) 區間總和查詢
struct seg {
    struct Node {
        int val, tag;
        Node *l, *r;
        Node(int v=0) : val(v), tag(0), l(nullptr), r(nullptr) {}
    };
    Node* root; int n;
    void init(int _n) {n = _n; root = new Node();}
    void push(Node* cur, int l, int r) {
        if(cur->tag) {
            cur->val += (r-l+1)*cur->tag;
            if(l!=r) {
                if (!cur->l) cur->l = new Node();
                if (!cur->r) cur->r = new Node();
                cur->l->tag += cur->tag;
                cur->r->tag += cur->tag;
            } 
        }
        cur->tag = 0;
    }
    void pull(Node* node, int l, int r) {
        int mid = l+r>>1;
        push(node->l, l, mid); push(node->r, mid+1, r);
        node->val = node->l->val + node->r->val;
    }
    void add(Node* cur, int l, int r, int ql, int qr, int val) {
        if (ql <= l && r <= qr) {cur->tag += val; push(cur, l, r); return;}
        if (!cur->l) cur->l = new Node();
        if (!cur->r) cur->r = new Node();
        int mid = (l + r) / 2;
        push(cur, l, r);
        if(ql<=mid) add(cur->l, l, mid, ql, qr, val);
        if(mid+1<=qr) add(cur->r, mid + 1, r, ql, qr, val);
        pull(cur, l, r);
    }
    int query(Node* cur, int l, int r, int ql, int qr) {
        if(ql<=l && r<=qr) {push(cur, l, r);return cur->val;}
        if (!cur->l) cur->l = new Node();
        if (!cur->r) cur->r = new Node();
        int mid = l+r>>1;
        int ans = 0;
        push(cur, l, r);
        if(ql<=mid) ans+=query(cur->l, l, mid, ql, qr);
        if(mid+1<=qr) ans+=query(cur->r, mid+1, r, ql, qr);
        pull(cur, l, r);
        return ans;
    }
    int query(int ql, int qr) {return query(root, 0, n, ql, qr);}
    void add(int ql, int qr, int val) {add(root, 0, n, ql, qr, val);}
} tree;