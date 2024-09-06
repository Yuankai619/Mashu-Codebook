//在有向圖裡的任兩點u、v，皆存在至少一條 u 到 v 的路徑以及 v 到 u 的路徑
//fill zero 注意多筆測資要改fill
//注意要0base
#define PB push_back
#define FZ(x) memset(x, 0, sizeof(x)) 
const int MXN = 1e5;
struct Scc {
    int n, nScc, vst[MXN], bln[MXN];//nScc 有幾個強連通分量
    vector<int> E[MXN], rE[MXN], vec;
    void init(int _n) {
        n = _n;
        for (int i = 0; i < MXN; i++) E[i].clear(), rE[i].clear();
    }
    void addEdge(int u, int v) {E[u].PB(v); rE[v].PB(u);}
    void DFS(int u) {
        vst[u] = 1;
        for(auto v : E[u]) if (!vst[v]) DFS(v);
        vec.PB(u);
    }
    void rDFS(int u) {
        vst[u] = 1;
        bln[u] = nScc;
        for(auto v : rE[u]) if (!vst[v]) rDFS(v);
    }
    void solve() {
        nScc = 0;
        vec.clear();
        FZ(vst);
        for(int i = 0; i < n; i++) if (!vst[i]) DFS(i);
        reverse(vec.begin(), vec.end());
        FZ(vst);
        for(auto v : vec) if (!vst[v]) {rDFS(v); nScc++;}
    }
} scc;