const int inf = 1e17;
int dis[105][105];
int back[105][105];
void fw() {
    for(int i=0;i<n;i++) dis[i][i] = 0;
    for(int k=0;k<n;++k){//O(N^3)
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(dis[i][k]!=inf&&dis[k][j]!=inf){//避免不連通圖
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                    if(i!=k) back[i][j] = back[i][k];
                }
            }
        }
    }
    for(int k=0;k<n;++k){//判斷負環
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(dis[i][k]!=inf&&dis[k][j]!=inf&&dis[k][k]<0){//避免不連通圖&&負環
                    dis[i][j]=-inf;
                }
            }
        }
    }
}
vector<int> path(int a, int b) {
    if(dis[a][b]==inf || dis[a][b]==-inf) return {-1};
    vector<int> ans;
    int now = a;
    while(now!=b) {
        ans.push_back(now);
        now = back[now][b];
    }
    ans.push_back(b);
    return ans;
}
for u, v in edge:
    back[u][v] = v
    dis[u][v] = 1
// if(graph[a][b]==-MAX)
//     cout<<"-Infinity\n";
// else if(graph[a][b]==MAX)
//     cout<<"Impossible\n";
// else
//     cout<<graph[a][b]<<"\n";
 