//1 1 2 5 14 42 132 429 1430 4862 16796
// O(N)，要記得開long long 跟設定 MOD
cat[0]=1; cat[1]=1;   
for(ll i=1 ; i<N ; i++) 
    cat[i] = cat[i-1]*(i*4-2)%MOD*qpow(i+1, MOD-2,MOD)%MOD;