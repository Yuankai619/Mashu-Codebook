const int maxn = 1<<22;  //1e6
int t,n,x;
int num[1000005];
int f[maxn],mx=1<<22;
signed main(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++) {cin>>x; num[i]=x; f[x]=x;}
	for(int i=0;i<22;i++)
		for(int j=0;j<(1<<22);++j)
			if(j&(1<<i)) {
			    f[j] = f[j^(1<<i)]?f[j^(1<<i)]:f[j];
			}
	for(int i=1 ; i<=n ;i++) printf("%d ", f[(mx-1)^num[i]]?f[(mx-1)^num[i]]:-1);
}