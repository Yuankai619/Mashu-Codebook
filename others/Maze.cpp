int dr[4]={0,1,0,-1};
int dc[4]={1,0,-1,0};
string str="RDLU";
inline bool inb(pii u){
    int x=u.first,y=u.second;
    return x>0 && x<=r && y>0 && y<=c;
}
void bfs(){
    pii u; int nx,ny;
    queue<pii> q; q.push(start);
    disa[start.first][start.second]=0;
    while(!q.empty()){
        u=q.front(); q.pop();
        if(!inb(u))continue;
        for(int i=0;i<4;++i){
            nx=u.first+dr[i];
            ny=u.second+dc[i];  
            if(disa[nx][ny]>=0 || g[nx][ny]=='#')continue;
            disa[nx][ny]=disa[u.first][u.second]+1;
            bac[nx][ny]=i;
            q.push({nx,ny});
        }
    }
}
void print(pii u){
    if(u==you)return;
    int f=bac[u.first][u.second];
    print({u.first-dr[f],u.second-dc[f]});
    cout<<str[f];
}