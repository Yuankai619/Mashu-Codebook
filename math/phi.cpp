// 計算小於n的數中與n互質的有幾個 O(sqrtN)
// a^b mod c = a^(b%phi(c) + phi(c)) mod c   : if b>=phi(c)
//           = a^b mod c                     : if b< phi(c)
int phi(int n){
    int res = n, a=n; 
    for(int i=2;i*i<=a;i++){
        if(a%i==0){
            res = res/i*(i-1);
            while(a%i==0) a/=i;
    }   }
    if(a>1) res = res/a*(a-1);
    return res;
}
// 建表 最大1e7
int phi[MXN];
void phitable(int n){
    phi[1]=1;
    for(int i=2;i<=n;++i){
        if(phi[i])continue;
        for(int j=i;j<=n;j+=i){
            if(phi[j]==0)phi[j]=j;
            phi[j]=phi[j]/i*(i-1);
        }
    }
}
