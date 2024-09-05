//總共m條邊，鬆弛n-1次->O(nm)
//在第n次做一次鬆弛，如果有點被鬆弛到，代表這張圖存在負環
for(int i=0;i<m;i++){
    if(dis[edge[i].u]+edge[i].w<dis[edge[i].v]){
        dis[edge[i].v]=dis[edge[i].u]+edge[i].w;
    }
}