const int MAXN = 1505;
enum traceType{LEFT,DIAG,UP};
int dp[MAXN*2][MAXN], pa[MAXN*2][MAXN];
char AA[MAXN*2];
void LCS(const char *a, const char *b, int m, int n){
	for(int i=1; i<=m; ++i)
		for(int j=1; j<=n; ++j){
			if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
			if(dp[i][j]==dp[i][j-1]) pa[i][j]=LEFT;
			else if(a[i-1]==b[j-1]) pa[i][j]=DIAG;
			else pa[i][j]=UP;
		}
}
int trace(int m, int n){
	int res = 0;
	while(m&&n){
		if(pa[m][n]==LEFT) --n;
		else if(pa[m][n]==UP) --m;
		else --m, --n, ++res;
	}
	return res;
}
void reRoot(int root,int m, int n){
	int i=root, j=1;
	while(j<=n&&pa[i][j]!=DIAG) ++j;
	if(j>n) return;
	pa[i][j] = LEFT;
	while(i<m&&j<n){
		if(pa[i+1][j]==UP) pa[++i][j]=LEFT;
		else if(pa[i+1][j+1]==DIAG)
			pa[++i][++j]=LEFT;
		else ++j;
	}
	while(i<m&&pa[++i][j]==UP) pa[i][j]=LEFT;
}
int CLCS(const char *a, const char *b){
	int m=strlen(a), n=strlen(b);
	strcpy(AA,a); strcpy(AA+m,a);
	LCS(AA,b,m*2,n);
	int ans = dp[m][n];
	for(int i=1; i<m; ++i){
		reRoot(i,m*2,n);
		ans=max(ans,trace(m+i,n));
	}
	return ans;
}