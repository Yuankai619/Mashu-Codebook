// len[s]是對應的回文長度
// num[s]是有幾個回文後綴
// cnt[s]是這個回文子字串在整個字串中的出現次數
// fail[s]是他長度次長的回文後綴，aba的fail是a
const int MXN = 1000010;
struct PalT{
    int nxt[MXN][26],fail[MXN],len[MXN]; 
    int tot,lst,n,state[MXN],cnt[MXN],num[MXN];
    int diff[MXN],sfail[MXN],fac[MXN],dp[MXN];
    char s[MXN]={-1};
    int newNode(int l,int f){
        len[tot]=l,fail[tot]=f,cnt[tot]=num[tot]=0;
        memset(nxt[tot],0,sizeof(nxt[tot]));
        diff[tot]=(l>0?l-len[f]:0);
        sfail[tot]=(l>0&&diff[tot]==diff[f]?sfail[f]:f);
        return tot++;
    }
    int getfail(int x){
        while(s[n-len[x]-1]!=s[n]) x=fail[x];
        return x;
    }
    int getmin(int v){
        dp[v]=fac[n-len[sfail[v]]-diff[v]];
        if(diff[v]==diff[fail[v]])
            dp[v]=min(dp[v],dp[fail[v]]);
        return dp[v]+1;
    }
    int push(){
        int c=s[n]-'a',np=getfail(lst);
        if(!(lst=nxt[np][c])){
            lst=newNode(len[np]+2,nxt[getfail(fail[np])][c]);
            nxt[np][c]=lst; num[lst]=num[fail[lst]]+1;
        }
        fac[n]=n;
        for(int v=lst;len[v]>0;v=sfail[v])
            fac[n]=min(fac[n],getmin(v));
        return ++cnt[lst],lst;
    }
    void init(const char *_s){
        tot=lst=n=0;
        newNode(0,1),newNode(-1,1);
        for(;_s[n];) s[n+1]=_s[n],++n,state[n-1]=push();
        for(int i=tot-1;i>1;i--) cnt[fail[i]]+=cnt[i];
    }
} palt;
// state 數組
//    state[i] 代表第 i 個字元為結尾的最長回文編號(編號是甚麼不重要)
//    
//    S = “abacaaba”
//    
//    以第 2(0-base) 個字元為結尾的最長回文是 aba
//    以第 7(0-base) 個字元為結尾的最長回文是 aba
//    兩個最長回文都相同，因此 state[2] 會等於 state[7]

// len 數組
//    求出某個 state 的長度
//    
//    S = “aababa”
//   
//    (0-base)
//    len[state[1]] = 2 (“aa”)
//    len[state[3]] = 3 (“aba”)
//    len[state[5]] = 5 (“ababa”)

// num 數組
//    某個state的回文有幾個回文後綴
//  
//    假設某個 state 代表的回文為 = “ababa” 為例
//    state 代表的回文的 num = 3
//    -> ababa -> aba -> a

// cnt 數組
//    某個 state 的回文在整個字串中出現次數
//   
//    S = “aababaa”
//    state[3] 代表的回文為 “aba” 在整個字串中出現 2 次
//    因此 cnt[state[3]] = 2

// fail數組
//    每個 state 的次長回文後綴的 state 編號
//   
//    S = “ababa”
//    len[fail[4]] = 3 (fail[4] = “aba”)
//    len[fail[2]] = 1 (fail[2] = “a”)
//    len[fail[0]] = 0 (fail[0] = “” 空字串)
//    0 所代表的 state 是空字串