// dp[位數][狀態]
// dp[pos][state]: 定義為目前位數在前導狀態為state的時候的計數
// ex: 求數字沒有出現66的數量 l~r
// -> dp[pos][1] 可表示計算pos個位數在前導出現一個6的計數  -> dp[3][1] 則計算  6XXX
// 模板的pos是反過來的，但不影響(只是用來dp記憶用)
// pos: 目前位數
// state: 前導狀態
// lead: 是否有前導0 (大部分題目不用但有些數字EX:00146如果有影響時要考慮)
// limit: 使否窮舉有被num限制
vector<int> num;
int dp[20][state];
int dfs(int pos, int state, bool lead, bool limit) {
    if(pos==num.size()) {
        //有時要根據不同state回傳情況
        return 1;
    }
    if(limit==false && lead==false && dp[pos][state]!=-1) return dp[pos][state]; 
    int up = limit?num[pos]:9;
    int ans = 0;
    for(int i=0 ; i<=up ; i++) {
        //有時要考慮那些狀況要continue
        ans += dfs(pos+1, state||(check[i]==2), lead&&i==0, limit&&i==num[pos]);
    }
    if(limit==false && lead==false) dp[pos][state] = ans;
    return ans;
}