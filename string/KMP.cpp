// 回傳所有匹配成功的起始位置，s為文本，t為匹配字串
// nxt表示為匹配失敗時要退回的位置，也是t字串的相等前綴後綴的最大長度
// *注意前綴後綴為長度最多為n-1的子字串
// nxt[j] = -1 if j=0 
//       0  if 沒有相等的前綴後綴
//       K  k 為相等前綴後綴的最大長度
// 以下為例子
//      j: 0 1 2 3 4 5 6
//      t: a b a a b e
// nxt[j]:-1 0 0 1 1 2 0
// O(n+m)，n為s長，m為t長
const int MXN = 1e6+5;
int nxt[MXN];
vector<int> KMP(string s,string t){
    int slen = s.length(), tlen = t.length(), i=0,j=0,k=-1;
    nxt[0]=-1;
    while(j<tlen){//build nxt
        if(k==-1 || t[j]==t[k]) nxt[++j] = ++k;
        else    k=nxt[k];
    }
    i=0,j=0;
    vector<int> ret;
    while(i<slen){// matching
        if(j==-1||s[i]==t[j]) i++,j++;
        else    j=nxt[j];
        if(j==tlen){
            ret.push_back(i-tlen+1);//1-base
            j=nxt[j];
        }
    }
    return ret;
}