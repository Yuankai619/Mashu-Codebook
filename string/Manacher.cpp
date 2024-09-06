// O(N)求以每個字元為中心的最長回文半徑 
// 頭尾以及每個字元間都加入一個 
// 沒出現過的字元，這邊以’@'為例 
// s為傳入的字串，len為字串長度  
// z為儲存以每個字元為中心的回文半徑+1(有包含'@'要小心)
// ex: s = "abaac" -> "@a@b@a@a@c@" 
// z =                [12141232121]  
const int MXN = 1e6+5;
int z[2*MXN];
char s[2*MXN];
void z_value_pal(char *s,int len,int *z){
  len=(len<<1)+1;
  for(int i=len-1;i>=0;i--)
    s[i]=i&1?s[i>>1]:'@';
  z[0]=1;
  for(int i=1,l=0,r=0;i<len;i++){
    z[i]=i<r?min(z[l+l-i],r-i):1;
    while(i-z[i]>=0&&i+z[i]<len&&s[i-z[i]]==s[i+z[i]])++z[i];
    if(i+z[i]>r) l=i,r=i+z[i];
} }