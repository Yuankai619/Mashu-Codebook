struct BIT {
    static const int mxn = 2005;
    int bit[mxn][mxn] = {0};
    int low(int x) {return x&-x;}
    void add(int x, int y, int val) {
        for(int i=x ; i<mxn ; i+=low(i)) for(int j=y ; j<mxn ; j+=low(j)) bit[i][j]+=val;
    }
    int query(int x, int y) {
        int ans = 0;
        for(int i=x ; i ; i-=low(i)) for(int j=y ; j ; j-=low(j)) ans+=bit[i][j];
        return ans;
    }
    int range_query(int a, int b, int x, int y) {
        return query(x, y) - query(x, b-1) - query(a-1, y) + query(a-1, b-1);
    }
} bit;