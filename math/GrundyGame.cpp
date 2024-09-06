//1, 2, 4, 7, 10, 20, 23, 26, 50, 53, 270 ... 1222
int SG[2020];
int mex(set<int> &S){
    for(int i = 0; i <= 2000; i++){ if(S.find(i) == S.end()) return i; }
}
void build(int n){
    set<int> S;
    for(int i = 1; i <= n; i++){
        S.clear();
        for(int j = 1; j < i; j++){ if(j != i - j) S.insert(SG[i - j] ^ SG[j]); }
        SG[i] = mex(S);
    }
}