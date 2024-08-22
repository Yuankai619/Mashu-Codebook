//注意值域
#define lowbit(x) (x & -x)
const int N = 1e5+5;
int bit[N];
struct BIT {
    int n;
    void init(int n){this->n = n;}
    void update(int x, int val) {
        for (; x <= n; x += lowbit(x))
            bit[x] += val;
    }
    int query(int x) {
        int res = 0;
        for (; x; x -= lowbit(x))
            res += bit[x];
        return res;
    }
    int query(int L, int R) { return query(R) - query(L - 1); }
}