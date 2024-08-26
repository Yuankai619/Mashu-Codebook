#include <bits/stdc++.h>
#define int long long int
using namespace std;
int n, st[1000005<<2], lazy[1000005<<2], old[1000005<<2];
vector <tuple<int, int, int, int>> v;
vector<int> sor;
void pull(int index, int l, int r) {
    if(lazy[index]) st[index] = old[index];
    else if(l==r) st[index] = 0;
    else st[index] = st[index<<1|1]+st[index<<1];
    // printf("pull %lld~%lld, %lld\n", l, r, st[index]);
    return;
}
void insert(int index, int s, int e, int l, int r, int k) {
    //printf("insert: range %lld~%lld, query %lld~%lld\n", s, e, l, r);
    if(l<=s && e<=r) {
        lazy[index] +=k;
        pull(index, s, e);
        return;
    }
    int mid = (s+e)/2;
    if(l<=mid) insert(index<<1, s, mid, l, r, k);
    if(mid<r) insert(index<<1|1, mid+1, e, l, r, k);
    pull(index, s, e);
}
void input(int index, int l, int r) {
    if(l==r) {
        old[index] = sor[l]-sor[l-1];
        return;
    }
    int mid = (l+r)/2;
    input(index<<1, l, mid);
    input(index<<1|1, mid+1, r);
    old[index] = old[index<<1] + old[index<<1|1];
    //cout<<l<<" to "<<r<<" is "<<old[index]<<endl;
    return;
}
// int diff=1000005;
signed main(){
    cin >> n;
    int l, r, d, u;
    for (int i = 0; i < n; i++){
        cin >> l >> d >> r >> u;
        // l+=diff;
        // d+=diff;
        // r+=diff;
        // u+=diff;
        sor.push_back(d);
        sor.push_back(u);
        v.push_back({l, d, u, 1});
        v.push_back({r, d, u, -1});
    }
    set<int> temp(sor.begin(), sor.end());
    sor = vector<int>(temp.begin(), temp.end());
    sort(sor.begin(), sor.end());
    for(int i=0 ; i<v.size() ; i++) {
        auto [a, b, c, k] = v[i];
        v[i] = make_tuple(a, (int)(lower_bound(sor.begin(), sor.end(), b)-sor.begin()), (int)(lower_bound(sor.begin(), sor.end(), c)-sor.begin()), k);
    }
    input(1, 1, sor.size()-1);
    // cout<<"get: ";
    // for(int i: sor) cout<<i<<" "; cout<<endl;
    sort(v.begin(), v.end());
    int pre=0;
    int ans=0;
    for(auto [pos, a, b, k]: v) {
        if(pre!=pos) {
            ans+=(pos-pre)*st[1];
            pre = pos;
        }
        insert(1, 1, sor.size()-1, a+1, b, k);
        // printf("now act: pos %lld,  %lld~%lld, act: %lld\n", pos, a+1, b, k);
        // printf("now ans: %lld\n", st[1]);
    }
    cout<<ans<<endl;
}
