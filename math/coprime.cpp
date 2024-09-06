// dp[i] 為認挑2個數字，最大公因數為i的組合數
// 把cnt[1~N]=1 可以建表phi(歐拉函數)
const int mxn =  1e6+7;
int cnt[mxn], dp[mxn];
int sol(vector<int> vec) {
    for(int u: vec) cnt[u]++;
    for(int i=mxn-1 ; i>=1 ; i--) {
        int a=0,b=0;
        for(int j=i ; j<mxn ; j+=i) {
            a+=cnt[j]; b+=dp[j];
        }
        dp[i] = (a*(a-1)/2) - b;
    }
    return dp[1];
}
