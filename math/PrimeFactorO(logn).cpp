vector<ll> ret;
void fac(ll x){
    if(x<2)return;
    if (miller_rabin(x)) {
      ret.push_back(x); return; }
    ll f = pollard_rho(x);
    fac(f); fac(x/f);
}
