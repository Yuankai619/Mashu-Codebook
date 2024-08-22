// a^b
const int MOD = 1e9+7;
int qpow(int n, int k,int p) {
    int ret = 1;
    for(;k; k >>= 1, n = n * n % p) if(k & 1) ret = ret * n % p;
    return ret;
}
// a^(b^c) = a^(q*(p-1)+r) = a^r so let b^c mod p-1
bc =qpow(b,c,p-1);
ans=qpow(a,bc,p);