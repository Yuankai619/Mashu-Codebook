int bin[mxn];
vector<tuple<int, int, int, int>> timing;
// int ans = n; 連通快數量
int fa(int x) {return bin[x]<0?x:fa(bin[x]);}
void uion(int x, int y) {
    x = fa(x); y = fa(y);
    timing.push_back({x, bin[x], y, bin[y]});
    if(x==y) return;
    //ans--;
    if(-bin[x] > -bin[y]) {bin[x]+=bin[y]; bin[y]=x;} else {bin[y]+=bin[x]; bin[x]=y;}
}
void undo() {
    auto [a,b,c,d] = timing.back();
    timing.pop_back(); //if(a!=c) ans++;
    bin[a] = b; bin[c] = d;
}