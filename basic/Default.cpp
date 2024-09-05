#include<bits/stdc++.h>
#include<chrono> // for timing
#pragma GCC optimize("O3,unroll-loops")
#pragma target optimize("avx2,bmi,bmi2,lzcnt,popcnt")
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pii pair<int,int>
#define ft first
#define sd second
#define int long long
#define ld long double
#define PI acos(-1)
#define SZ(x) (int)x.size()
#define all(v) (v).begin(), (v).end()
#define  _for(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;
template<typename T>
ostream& operator<<(ostream& os,const vector<T>& vn){
	for(int i=0;i<vn.size();++i)os<<vn[i]<<" ";
	return os;
}
template<typename T>
ostream& operator<<(ostream& os,const set<T>& vn){
	for(typename set<T>::iterator it=vn.begin();it!=vn.end();++it)os<<*it<<" ";
	return os;
}
mt19937 mt(hash<string>()("Mashu_AC_Please")); //mt();
// mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
// g++ a.cpp -Wall -Wshadow -fsanitize=undefined -o a.exe
// ./a.exe
const int MXN=2e5+5;
const int INF=INT_MAX;
void sol() {}
signed main() {
    // auto start=chrono::high_resolution_clock::now();
    // #ifdef LOCAL
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif
    IO
    int t=1;
    // cin>>t;
    while(t--) {sol();}
    // auto stop = chrono::high_resolution_clock::now();
    // auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    // cerr<<"Time:"<<duration.count()<<" ms\n";
}
