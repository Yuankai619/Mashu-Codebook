//注意值域
const int N = 1e5+5;
int bit[N];
struct BIT {
    int n;
    void init(int _n){ n = _n;}
    int low(int x) {return x&-x;}
    void update(int x, int val) {
        while(x<n) bit[x]+=val, x+=low(x);
    }
    int query(int x) {
        int res = 0;
        while(x) res += bit[x], x-=low(x);
        return res;
    }
    int query(int l, int r) {return query(r) - query(l - 1); }
};