//預設為小寫字母
//return the number of distinct non-empty subsequences of sting
#define int long long
int mod = 1e9 + 7;
vector<int> cnt(26);
int distinct_subsequences(string s) {
    for (char c : s)
    cnt[c - 'a'] = accumulate(begin(cnt), end(cnt), 1LL) % mod;
    return accumulate(begin(cnt), end(cnt), 0LL) % mod;
}