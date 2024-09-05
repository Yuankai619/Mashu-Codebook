// < long long 
ll mul(ll x,ll y,ll mod){
	ll ret=x*y-(ll)((long double)x/mod*y)*mod;
	// ll ret=x*y-(ll)((long double)x*y/mod+0.5)*mod;
	return ret<0?ret+mod:ret;
}
