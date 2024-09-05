// does not work when n is prime  O(n^(1/4))
ll f(ll x, ll mod){ return add(mul(x,x,mod),1,mod); }
ll pollard_rho(ll n) {
    if(!(n&1)) return 2;
    while(true){
    ll y=2, x=rand()%(n-1)+1, res=1;
    for(int sz=2; res==1; sz*=2) {
        for(int i=0; i<sz && res<=1; i++) {
            x = f(x, n);
            res = __gcd(abs(x-y), n);
        }
        y = x;
    }
    if (res!=0 && res!=n) return res;
} }
// 如果被卡隨機 用下面的
ll f(ll x,ll c,ll mod){return add(mul(x,x,mod),c,mod);} 
ll pollard_rho(ll n){
    ll c=1,x=0,y=0,p=2,q,t=0;
    while(t++%128 or __gcd(p,n)==1){
        if(x==y)c++,y=f(x=2,c,n);
        if(q=mul(p,abs(x-y),n))p=q;
        x=f(x,c,n);y=f(f(y,c,n),c,n);
    }
    return __gcd(p,n);
}
