// tree.init(n,m) 二維大小
// tree.add(qx, qy, val) 座標 (qx, qy) 加值 val
// tree.query(qlx, qly, qrx, qry) 座標 左下角(qlx, qly)到 座標 右上角(qrx, qry) 的矩陣總和
// 單點加值
// 區間查詢
// O(lg(n)lg(m))
struct segy {
    int n;
    struct Node {
        int val;
        Node *l, *r;
        Node(int v=0) : val(v), l(nullptr), r(nullptr) {}
    };
    segy(int _n=1e9) {n=_n; root=new Node();}
    Node* root;
    void init(int _n=1e9) {
        n = _n;
        root = new Node();
    }
    void pull(Node* node) {
        node->val = (node->l?node->l->val:0) + (node->r?node->r->val:0);
    }
    void add(Node* cur, int l, int r, int pos, int val) {
        if (l==r) {
            cur->val += val;
            return;
        }
        int mid = l+r>>1;
        if(pos<=mid) {if(!cur->l) cur->l = new Node();add(cur->l, l, mid, pos, val);}
        else {if(!cur->r) cur->r = new Node();add(cur->r, mid + 1, r, pos, val);}
        pull(cur);
    }

    int query(Node* cur, int l, int r, int ql, int qr) {
        if(ql<=l && r<=qr) {
            return cur->val;
        }
        int mid = l+r>>1;
        int ans = 0;
        if(ql<=mid) {if(!cur->l) cur->l = new Node(); ans+=query(cur->l, l, mid, ql, qr);}
        if(mid+1<=qr) {if(!cur->r) cur->r = new Node(); ans+=query(cur->r, mid+1, r, ql, qr);}
        pull(cur);
        return ans;
    }
    int query(int ql, int qr) {
        return query(root, 0, n, ql, qr);
    }
    void add(int pos, int val) {
        add(root, 0, n, pos, val);
    }
};
struct segx {
    struct Node {
        segy * tree_y;
        Node *l, *r;
        Node(int m) : tree_y(new segy(m)), l(nullptr), r(nullptr) {}
    };
    Node* root;
    int n,m;
    segx(int _n=1e9, int _m=1e9) {n=_n; m=_m; root=new Node(m);}
    void init(int _n=1e9, int _m=1e9) {n=_n; m=_m; root=new Node(m);}
    void add(Node* cur, int l, int r, int qx, int qy, int val) {
        if(l!=r) {
            int mid = (l + r) / 2;
            if(qx<=mid) {if(!cur->l) cur->l = new Node(m); add(cur->l, l, mid, qx, qy, val);}
            else {if(!cur->r) cur->r = new Node(m); add(cur->r, mid + 1, r, qx, qy, val);}
        }
        cur->tree_y->add(qy, val);
    }
    int query(Node* cur, int lx, int rx, int qlx, int qrx, int qly, int qry) {
        if(qlx<=lx && rx<=qrx) {
            return cur->tree_y->query(qly, qry);
        }
        int mid = lx+rx>>1;
        int ans = 0;
        if(qlx<=mid) {if(!cur->l) cur->l = new Node(m); ans+=query(cur->l, lx, mid, qlx, qrx, qly, qry);}
        if(mid+1<=qrx) {if(!cur->r) cur->r = new Node(m); ans+=query(cur->r, mid+1, rx, qlx, qrx, qly, qry);}
        return ans;
    }
    int query(int qlx, int qly, int qrx, int qry) {
        return query(root, 0, n, qlx, qrx, qly, qry);
    }
    void add(int qx, int qy, int val) {
        add(root, 0, n, qx, qy, val);
    }
} tree;