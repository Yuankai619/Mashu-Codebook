#define i64 __int64
vector<i64> ret;
void fact(i64 x) {
    if (miller_rabin(x)) {
      ret.push_back(x);
      return;
    }
    i64 f = pollard_rho(x);
    fact(f); fact(x/f);
}