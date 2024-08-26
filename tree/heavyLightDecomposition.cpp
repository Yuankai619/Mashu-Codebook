
const int MXN = 2e5+7;
int top[MXN], son[MXN], dfn[MXN], rnk[MXN], dep[MXN], father[MXN];
vector<int> edge[MXN];
int dfs1(int v, int fa, int d) {
    int maxsz = -1, maxu, total = 1;
    dep[v] = d;
    father[v] = fa;
    for(int u: edge[v]) {
        if(fa == u) continue;
        int temp = dfs1(u, v, d+1);
        total += temp;
        if(temp>maxsz) {
            maxsz = temp;
            maxu = u;
        }
    }
    if(maxsz==-1) son[v] = -1;
    else son[v] = maxu;
    return total;
}

int times = 1;
void dfs2(int v, int fa) {
    rnk[times] = v;
    dfn[v] = times++;
    top[v] = (fa==-1 || son[fa] != v ? v : top[fa]); 
    if(son[v]!=-1) dfs2(son[v], v);
    for(int u: edge[v]) {
        if(fa == u || u == son[v]) continue;
        dfs2(u, v);
    }
}
//rnk: 剖分後的編號 (rnk[時間] = 原點)
//dfn: 剖分後的編號 (dfn[原點] = 時間)
//top: 剖分的頭頭
//son: 剖分的重兒子