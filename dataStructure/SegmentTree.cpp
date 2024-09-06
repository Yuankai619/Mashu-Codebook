struct seg {
    #define left (index<<1)
    #define right (index<<1|1)
    static const int MXN = 200005;
    int val[MXN*4], tag[MXN*4];
    int a[MXN];
    void push(int index, int l, int r) {
        if(tag[index]!=0) {
            val[index]+=tag[index]*(r-l+1);
            if(l!=r) {
                tag[left] += tag[index];
                tag[right] += tag[index];
            }
            tag[index]=0;
        }
    }
    void pull(int index, int l, int r) {
        int mid = l+r>>1;
        push(left, l, mid);
        push(right, mid+1, r);
        val[index] = val[left]+val[right];
    }
    void build(int index, int l, int r) {
        if(l==r) {val[index] = a[l]; return;}
        int mid = (l+r)>>1;
        build(left, l, mid); build(right, mid+1, r);
        pull(index, l, r);
    }
    void add(int index, int s, int e, int l, int r, int v) {
        if(e<l || r<s) return;
        if(l<=s && e<=r) {tag[index] += v; push(index, s, e); return;}
        int mid = (s+e)>>1;
        push(index, s, e);
        add(left, s, mid, l, r, v); add(right, mid+1, e, l, r, v);
        pull(index, s, e);
    }
    int query(int index, int s, int e, int l, int r) {
        if(e<l || r<s) return 0;
        if(l<=s && e<=r) {push(index, s, e); return val[index];}
        push(index, s, e);
        int mid = (s+e)>>1;
        return query(right, mid+1, e, l, r)+query(left, s, mid, l, r);
    }
} tree;