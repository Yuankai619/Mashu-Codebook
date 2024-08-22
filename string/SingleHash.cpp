//字串雜湊前的idx是0-base，雜湊後為1-base
//H[R] - H[L-1] * p^(R-L+1)
//cmp的+modl是為了防止負數
//記得build完之後要buildPow
//小心遇到hash出負數要記得+modl
#define int long long
const int p = 75577, modl = 1e9 + 7,MXN = 1e6+5;
int Hash[MXN],qpow[MXN];
void build(const string& s) {
    Hash[0]=0;
    for(int i=1; i<=s.size(); i++)
        Hash[i] = (Hash[i-1] * p + s[i-1]) % modl;
}
void buildPow(){
    qpow[0]=1;
    for(int i=1;i<MXN;++i) qpow[i]=qpow[i-1]*p%modl;
}
bool cmp(int i, int j, int len) {
    return (Hash[i+len-1] - Hash[i-1] * qpow[len] % modl + modl) % modl == 
    (Hash[j+len-1] - Hash[j-1] * qpow[len] % modl + modl) % modl;
}
int get(int i, int j) {
    return (Hash[j]-Hash[i-1]*qpow[j-i+1]%modl+modl)%modl;
}