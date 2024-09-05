//總共m條邊，鬆弛n-1次->O(nm)
//在第n次做一次鬆弛，如果有點被鬆弛到，代表這張圖存在負環
for(int j = 0; j < n-1; j++){
    for(int i = 0; i < m; i++){ // 對於所有邊都嘗試鬆弛
        if(dis[ edge[i].to ] > dis[ edge[i].from ] + edge[i].weight){
            dis[ edge[i].to ] = dis[ edge[i].from ] + edge[i].weight;
        }
    }
}