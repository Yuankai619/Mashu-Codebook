#define LL long long
// n < 4,759,123,141        3 :  2, 7, 61
// n < 1,122,004,669,633    4 :  2, 13, 23, 1662803
// n < 3,474,749,660,383          6 :  pirmes <= 13
// n < 2^64                       7 : 2, 325, 9375, 28178, 450775, 9780504, 1795265022
// Make sure testing integer is in range [2, n−2] if
// you want to use magic.
LL magic[]={}; // **<- here**
__int128 mypow(__int128 a, __int128 b, __int128 p) {
    if(b==0) return 1;
    else if(b==1) return a%p;
    else if(b%2==0) {
        __int128 t=mypow(a, b/2, p);
        t = t*t%p;
        return t;
    } else if(b%2==1){
        __int128 t=mypow(a, b/2, p);
        t = t*t%p;
        t = t*a%p;
        return t;
    }
    return 0;
}
__int128 mul(__int128 a, __int128 b, __int128 p) {return (a*b)%p;}
__int128 add(__int128 a, __int128 b, __int128 p) {return (a+b)%p;}
bool witness(LL a,LL n,LL u,int t){
	if(!a) return 0;
	LL x=mypow(a,u,n);
	for(int i=0;i<t;i++) {
		LL nx=mul(x,x,n);
		if(nx==1&&x!=1&&x!=n-1) return 1;
		x=nx;
	}
	return x!=1;
}
bool miller_rabin(LL n) {
	int s=(magic number size);  // **<-here**
	// iterate s times of witness on n
	if(n<2) return 0;
	if(!(n&1)) return n == 2;
	LL u=n-1; int t=0;
	// n-1 = u*2^t
	while(!(u&1)) u>>=1, t++;
	while(s--){
		LL a=magic[s]%n;
		if(witness(a,n,u,t)) return 0;
	}
	return 1;
}
// does not work when n is prime  O(n^(1/4))
LL f(LL x, LL mod){ return add(mul(x,x,mod),1,mod); }
LL pollard_rho(LL n) {
	if(!(n&1)) return 2;
    while(true){
        LL y=2, x=rand()%(n-1)+1, res=1;
        for(int sz=2; res==1; sz*=2) {
            for(int i=0; i<sz && res<=1; i++) {
                x = f(x, n);
                res = __gcd(abs(x-y), n);
            }
            y = x;
        }
        if (res!=0 && res!=n) return res;
    }
}
vector<int> factor;
void get_factor(int x) {
    if(x==1) return;
    if(prime[x]) {
        factor.push_back(x);
        return;
    }
    int fac = pollard_rho(x);
    get_factor(fac); get_factor(x/fac);
}