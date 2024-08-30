// vec
// {{a, b, c},
//  {a, b, c},
//     ...    
//  {a, b, c}}
// 貼上 BIT 模板
// 三維偏序
// a <= a, b <= b, c <= c
map<vector<int>, int> cnt;
int cdq(vector<vector<int>> &vec, int l, int r) {
    if(l==r) return 0;
    int mid = l+r>>1;
    int ans = cdq(vec, l, mid)+cdq(vec, mid+1, r);
    vector<vector<int>> temp;
    for(int i=l, j=mid+1 ; i<=mid || j<=r ;) {
        while(i<=mid && (j>r || vec[i][1] <= vec[j][1])) {bit.add(vec[i][2],cnt[vec[i]]); temp.push_back(vec[i++]);}
        if(j<=r) {
            temp.push_back(vec[j]);
            ans += bit.query(vec[j][2]);
        }
    }
    for(int i=l ; i<=mid ; i++) bit.add(vec[i][2],-cnt[vec[i]]);
    for(int i=l ; i<=r ; i++) vec[i] = temp[i-l];
    return ans;
}
int solve(vector<vector<int>> &vec) {
    bit.init(2e5+5);
    for(vector<int> v: vec) cnt[v]++;
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    return cdq(vec, 0, vec.size()-1);
}
