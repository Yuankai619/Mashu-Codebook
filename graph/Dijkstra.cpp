int dis[N],vis[N];
void dijkstra(int s){//O(V^2+E)
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[s] = 0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,s});
    while(!pq.empty()){
        auto [nowd,now] = pq.top();
        pq.pop();
        if(vis[now])
            continue;
        vis[now] = 1;
        for(auto [nxt,w]: graph[now]){
            if(dis[nxt] > dis[now] + w){
                dis[nxt] = dis[now] + w;
                pq.push({dis[nxt],nxt});
            }
        }
    }
}