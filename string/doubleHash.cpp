//字串雜湊前的idx是0-base，雜湊後為1-base
//即區間為 [0,n-1] -> [1,n]
//若要取得區間[L,R]的值則
//H[R] - H[L-1] * p^(R-L+1)
//cmp為比較從i開始長度為len的字串和從j開始長度為len的字串是否相同
//(h[i+len-1] - h[i-1] * qpow(p, len) % modl + modl)
#define int long long
#define x first
#define y second
const int P1 = 75577, P2 = 17, MOD = 1e9 + 7,MXN = 1e6+5;
pair<int,int> Hash[MXN];
int qpow[2][MXN];
void build(const string& s){
  pair<int,int> val = make_pair(0,0);
  Hash[0]=val;
  for(int i=1; i<=s.size(); i++){
  val.x = (val.x * P1 + s[i-1]) % MOD;
  val.y = (val.y * P2 + s[i-1]) % MOD;
  Hash[i] = val;
  }
}
void buildPow(){
    qpow[0][0]=qpow[1][0]=1;
    for(int i=1;i<MXN;++i){
        qpow[0][i]=qpow[0][i-1]*P1%MOD;
        qpow[1][i]=qpow[1][i-1]*P2%MOD;
    }
}
bool cmp( int i, int j, int len ) {
    return ((Hash[i+len-1].x-Hash[i-1].x*qpow[0][len]%MOD+MOD)%MOD == (Hash[j+len-1].x-Hash[j-1].x*qpow[0][len]%MOD+MOD)%MOD)
    && ((Hash[i+len-1].y-Hash[i-1].y*qpow[1][len]%MOD+MOD)%MOD == (Hash[j+len-1].y-Hash[j-1].y*qpow[1][len]%MOD+MOD)%MOD);
}
pair<int, int> get(int i, int j) {
    return {(Hash[j].x-Hash[i-1].x*qpow[0][j-i+1]%MOD+MOD)%MOD, (Hash[j].y-Hash[i-1].y*qpow[1][j-i+1]%MOD+MOD)%MOD};
}