//無向圖上，不會產生割點的連通分量稱為點雙連通分量，0base
#define PB push_back
#define REP(i, n) for(int i = 0; i < n; i++)
struct BccVertex {
    int n, nScc, step, dfn[MXN], low[MXN];
    vector<int> E[MXN], sccv[MXN];
    int top, stk[MXN];
    void init(int _n) {
        n = _n;
        nScc = step = 0;
        for (int i = 0; i < n; i++)
            E[i].clear();
    }
    void addEdge(int u, int v) {E[u].PB(v); E[v].PB(u);}
    void DFS(int u, int f) {
        dfn[u] = low[u] = step++;
        stk[top++] = u;
        for (auto v : E[u]) {
            if (v == f) continue;
            if (dfn[v] == -1) {
                DFS(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] >= dfn[u]) {
                    int z;
                    sccv[nScc].clear();
                    do {
                        z = stk[--top];
                        sccv[nScc].PB(z);
                    } while (z != v);
                    sccv[nScc++].PB(u);
                }
            }
            else low[u] = min(low[u], dfn[v]);
        }
    }
    vector<vector<int>> solve() {//回傳每個點雙聯通分量
        vector<vector<int>> res;
        for (int i = 0; i < n; i++) dfn[i] = low[i] = -1;
        for (int i = 0; i < n; i++) if (dfn[i] == -1) {top = 0; DFS(i, i);}
        REP(i, nScc) res.PB(sccv[i]);
        return res;
    }
} graph;
