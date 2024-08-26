// 1. dfs 先做子樹
// 2. 葉節點的hash值為1
// 3. 對於節點x，其hash值為紀錄x的所有子樹的hash值(紀錄到temp)，然後由小排到大(排除子樹的隨機問題)
// 4. n表示節點x有幾個子樹，p和MOD通常為一個很大的質數，由此算出x的hash值
// 5. 樹根的hash值即為整顆樹的hash值，若兩顆樹的hash值相同，則兩棵樹就是同構
const int MXN = 200005;
int subtree_sz[MXN];
int hash_[MXN];
int base = 44560482149;
int MOD = 274876858367;
int dfs(int x, int fa, vector<int>* edge){
    vector<int> temp;
    subtree_sz[x] = 1;
    for(int child : edge[x]){
        if(child==fa) continue;
        temp.push_back(dfs(child, x, edge));
        subtree_sz[x] += subtree_sz[child];
    }
    sort(temp.begin(), temp.end());
    int ret = subtree_sz[x];
    for(int v : temp){
        ret = (((ret * base + v + ret) % MOD + ret) % MOD + v) % MOD ;
    }
    hash_[x] = ret;
    return ret;
}