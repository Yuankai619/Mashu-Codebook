vector<int> comb; //產生1~n位數的二進位組合
void genBinComb(int n){
    for(int i=1;i<(1<<n);++i){
        string s = bitset<5>(i).to_string();//bitset大小要記得設
        comb.push_back(stoi(s));
    }
}