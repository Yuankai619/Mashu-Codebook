// O(n)
//z[i] = lcp(s[1...],s[i...])
//1base
int z[MAXN];
void Z_value(const string& s) {
	int i, j, left, right, len = s.size();
	left=right=0; z[0]=len;
	for(i=1;i<len;i++) {
		j=max(min(z[i-left],right-i),0);
		for(;i+j<len&&s[i+j]==s[j];j++);
		z[i]=j;
		if(i+z[i]>right) {
			right=i+z[i];
			left=i;
}   }   }