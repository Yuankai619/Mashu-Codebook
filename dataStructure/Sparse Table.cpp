//st[i][j]表示[i,i+2^j-1]的最值,區間最大長度為log2(n)
//i為1base
const int N = 5e4+5;
int stMax[N][20],stMin[N][20],a[N];
struct ST{
    int k;
    void build(int n,int a[]){
        k=log2(n); 
        for(int i = 1; i <= n; i++)  stMin[i][0] = stMax[i][0] = a[i];
        for(int j = 1; j <= k; j++){
            for(int i = 1; i + (1 << j) - 1 <= n; i++){
                stMax[i][j] = max(stMax[i][j - 1], stMax[i + (1 << (j - 1))][j - 1]);
                stMin[i][j] = min(stMin[i][j - 1], stMin[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    int queryMax(int l,int r){
        int j = log2(r-l+1);
        return max(stMax[l][j],stMax[r-(1<<j)+1][j]);
    }
    int queryMin(int l,int r){
        int j = log2(r-l+1);
        return min(stMin[l][j],stMin[r-(1<<j)+1][j]);
    }
}st;