struct cmp{inline bool operator()(const int a,const int b){return a<b;}};//common use
auto cmp=[](vector<int> a, vector<int> b) {return a[1]<b[1];};//for set use
set<vector<int>, decltype(cmp)> prepare, done;