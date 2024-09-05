const int MXN = 1e7+7; //if>1e7 TLE
int np[MXN],fac[MXN],num[MXN];
void table(){
    np[1]=1;
    for(int i=2;i<MXN;++i){
        if(np[i])continue;
        for(int j=i;j<MXN;j+=i){
            if(i!=j)np[j]=1;
            fac[j]=i;
            num[j]++;
        }
    }
}
//質因數分解
vector<int> res;
void div(int x){
    for(;x>1;x/=fac[x])res.push_back(fac[x]);
}
