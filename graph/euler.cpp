const int MXN = 2e5+7;
struct ola{
    vector<pair<int, int>> edge[MXN];
    int ind[MXN], ru[MXN], use[MXN*3], es=0, n, go;
    void init(int _n) {n = _n; for(int i=0 ; i<n ; i++) edge[i].clear(), ind[i]=0;}
    void add_edge(int a, int b) {
        use[es] = 0;
        edge[a].push_back({b, es});
        edge[b].push_back({a, es++});
        ru[a]++; ru[b]++;
    }
    bool check() {
        int cnt = 0;
        for(int i=0 ; i<n ; i++) {if(ru[i]&1) go = i,cnt++;}
        if(cnt==0 || cnt==2) return true;
        return false;
    }
    vector<int> ans;
    void dfs(int x) {
        for(int i=ind[x] ; i<edge[x].size() ; i=ind[x]) {
            int u = edge[x][i].first, pos = edge[x][i].second;
            ind[x]++;
            if(!use[pos]) {
                use[pos]=1;
                dfs(u);
            }
        }
        ans.push_back(x);
    }
    vector<int> solve() {
        if(!check()) return {-1};
        ans.clear(); dfs(go);
        if(ans.size()!=es+1) return {-1};
        return ans;
    }
} euler;