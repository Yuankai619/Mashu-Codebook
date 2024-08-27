// * 給一個字串s
// * 求長度為len且有包含s的字串有幾種
// * 呼叫solve(s, len)
const int len = 1005;
int aut[len][26];
int dp[len][len];
const int mod = 1e9+7;
void prefix(string &s, vector<int> &pi) {
    for(int i=1, j=0 ; i<s.size() ; i++) {
        while(j>0 && s[i]!=s[j]) j = pi[j-1];
        if(s[i]==s[j]) j++;
        pi[i] = j;
    }
}
void automata(string &s, vector<int> &pi) {
    for(int i=0 ; i<s.size() ; i++) {
        for(int c=0 ; c<26 ; c++) {
            if(i>0 && c+'A' != s[i]) aut[i][c] = aut[pi[i-1]][c];
            else aut[i][c] = i + (c + 'A'==s[i]);
        }
    }
}
int quai(int x, int n) {
    if(n==0) return 1;
    int mid = quai(x,n/2);
    mid = mid*mid%mod;
    if(n&1) return mid*x%mod;
    return mid;
}
int solve(string s, int len) {
    vector<int> pi(s.size(), 0);
    prefix(s, pi);
    automata(s, pi);
    int n = s.size(), ans = quai(26, len);
    dp[0][0] = 1;
    for(int i=0 ; i<len ; i++) {
        for(int j=0 ; j<n ; j++) {
            for(int c=0 ; c<26 ; c++) {
                dp[i+1][aut[j][c]] += dp[i][j];
                dp[i+1][aut[j][c]] %= mod;
            }
        }
    }
    for(int i=0 ; i<n ; i++) ans = (ans - dp[len][i] + mod)%mod;
    return ans;
}