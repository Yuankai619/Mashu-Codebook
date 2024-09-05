#define ll long long
#define lll __int128
ll mypow(lll n,lll k,ll p){
    ll res=1;
    for(;k;k>>=1,n=n*n%p)if(k&1)res=res*n%p;
    return res;
}
ll mul(ll a,ll b,ll mod){   
    lll c=a%mod;
    return c*b%mod;
}
ll add(ll x,ll y,ll mod){
    lll c=x;c+=y;
    return c%mod;
}
