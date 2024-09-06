//最大流量上的最小花費
//最大流量優先，相同才是找最小花費，複雜度O(V^2*E^2)
// flow.init(n,s,t):有n個點(0~n-1)，起點s終點t
// flow.add_edge(u,v,f,c):建一條邊，從u點到v點流量為f，每一單位流量的花費為c
// flow.solve():回傳一個pair(maxFlow,minCost)
// 限制: 圖不能有負環
// 網路最大流的add_edge(u,v,f)可以無痛轉成最大流量上的最小花費add_edge(u,v,1,f)即建立一條從u到v的邊流量為1，單位流量花費為f
//O(V^2 E^2)
#define ll long long
struct zkwflow{
    static const int maxN=20000;
    struct Edge{ int v,f,re; ll w;};
    int n,s,t,ptr[maxN]; bool vis[maxN]; ll dis[maxN];
    vector<Edge> E[maxN];
    void init(int _n,int _s,int _t){
        n=_n,s=_s,t=_t;
        for(int i=0;i<n;i++) E[i].clear();
    }
    void add_edge(int u,int v,int f,ll w){
        E[u].push_back({v,f,(int)E[v].size(),w});
        E[v].push_back({u,0,(int)E[u].size()-1,-w});
    }
    bool SPFA() {
        fill_n(dis, n, LLONG_MAX);
        fill_n(vis, n, false);
        queue<int> q; 
        q.push(s); dis[s]=0;
        while(!q.empty()) {
            int u = q.front(); q.pop(); 
            vis[u] = false;
            for(auto &it: E[u]){
                if(it.f>0 && dis[it.v]>dis[u]+it.w){
                    dis[it.v] = dis[u]+it.w;
                    if(!vis[it.v]) {vis[it.v] = true; q.push(it.v);} 
                } 
            } 
        }
        if(dis[t]==LLONG_MAX) return false;
        // 不管流量是多少，花費不能是正數時加上這行 (最小花費可行流)
        // if(dis[t] >= 0) return false;
        return true;
    }
    int DFS(int u, int nf) {
        if(u==t) return nf;
        int res = 0; vis[u] = true;
        for(int &i=ptr[u] ; i<(int)E[u].size() ; i++) {
            auto &it = E[u][i];
            if(it.f>0 && dis[it.v]==dis[u]+it.w && !vis[it.v]) {
                int tf = DFS(it.v, min(nf, it.f));
                res += tf;
                nf-=tf;
                it.f-=tf;
                E[it.v][it.re].f += tf;
                if(nf==0) { vis[u]=false; break; }
            }
        }
        return res;
    }
    pair<int,ll> solve(){
        int flow = 0; ll cost = 0;
        while (SPFA()){
            fill_n(ptr, n, 0);
            int f = DFS(s, INT_MAX); 
            flow += f; cost += dis[t]*f;
        }
        return {flow, cost};
    } // reset: do nothing
} flow;