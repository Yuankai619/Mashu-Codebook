for(int k=0;k<n;++k){//O(N^3)
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(graph[i][k]!=MAX&&graph[k][j]!=MAX)//避免不連通圖
                graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
        }
    }
}
for(int k=0;k<n;++k){//判斷負環
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(graph[i][k]!=MAX&&graph[k][j]!=MAX&&graph[k][k]<0){//避免不連通圖&&負環
                graph[i][j]=-MAX;
            }
        }
    }
}
// if(graph[a][b]==-MAX)
//     cout<<"-Infinity\n";
// else if(graph[a][b]==MAX)
//     cout<<"Impossible\n";
// else
//     cout<<graph[a][b]<<"\n";
 