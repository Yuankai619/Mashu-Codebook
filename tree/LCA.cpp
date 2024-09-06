//先建edge[MXN] 跑dfs，再跑makeanc
//之後才可以呼叫lca 0-base
const int MXN=1e5;
const int logN=__lg(MXN);
int tin[MXN],tout[MXN],anc[MXN][logN+1];
vector<int> edge[MXN];
int ti=0;
void dfs(int x,int f){
    anc[x][0]=f;
    tin[x]=ti++;
    for(int u:edge[x]){
        if(u==f)continue;
        dfs(u,x);
    }
    tout[x]=ti++;
}
// x is y's anc
inline bool isanc(int x,int y){
    return tin[x]<=tin[y] && tout[x]>=tout[y];
}
int lca(int x,int y){
    if(isanc(x,y))return x;
    if(isanc(y,x))return y;
    for(int i=logN;i>=0;--i){
        if(!isanc(anc[y][i],x)){
            y=anc[y][i];
        }
    }
    return anc[y][0];
}
void makeanc(int n){
    for(int i=1;i<=logN;++i)for(int j=0;j<n;++j)
        anc[j][i] = anc[anc[j][i-1]][i-1];
}
