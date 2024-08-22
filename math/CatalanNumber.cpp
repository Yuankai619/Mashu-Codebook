// O(N)，要記得開long long 跟設定 MOD
cat[0]=1; cat[1]=1;   
for(ll i=1 ; i<N ; i++) {
    cat[i+1] = cat[i]*(i*4+2)%MOD*qpow(i+2, MOD-2)%MOD;
}