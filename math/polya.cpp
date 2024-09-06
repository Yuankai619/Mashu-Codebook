// n個點的環 m種染色 求不重複的方案數
int polya(int n,int m){
    int ans=0;
    for(int i=1;i*i<=n;++i){
        if(n%i)continue;
        ans=(ans+qpow(m,i)*phi(n/i)%MOD)%MOD;
        if(i*i!=n)ans=(ans+qpow(m,n/i)*phi(i)%MOD)%MOD;
    }
    return (ans*qpow(n,MOD-2))%MOD; //除掉 可以用旋轉得到的方案
}