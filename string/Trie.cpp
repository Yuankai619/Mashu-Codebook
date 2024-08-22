//cnt為記錄有多少個一樣的單詞且end的時候才有數字
const int MXN=1e6+5;//MXN取文本長
int trie[MXN][26], cnt[MXN],tot=0;//0 base
void update(string s){
    int p=0;//0 base
    for(int i=0;i<s.size();++i){
        int ch = s[i]-'a';
        if(!trie[p][ch]) trie[p][ch]=++tot;
        p = trie[p][ch];
    }
    cnt[p]++;
}
int query(string s){
    int p=0;
    for(int i=0;i<s.size();++i){
        int ch=s[i]-'a';
        p = trie[p][ch];
        if(!p) return 0;
    }
    return cnt[p];
}
void visualizeTrie(int node = 0, int depth = 0) {//for debug
    for (int i = 0; i < 26; ++i) {
        if (trie[node][i]) {
            for (int j = 0; j < depth; ++j) cout << "  ";
            cout << (char)('a' + i) << " (" << cnt[trie[node][i]] << ")\n";
            visualizeTrie(trie[node][i], depth + 1);
        }
    }
}