// 出來的是保證能做出MST的邊 邊是亂的 ~~魔術師~~
// 需要swap(u.first.first,u.first.second) + sort unique
#define ld long long 
struct Pt{
    ld x,y;
    Pt(ld x=0,ld y=0):x(x),y(y){}
    Pt operator+(const Pt &a) const {return Pt(x+a.x, y+a.y);  }
    Pt operator-(const Pt &a) const {return Pt(x-a.x, y-a.y);  }
};
vector<pair<pair<int,int>,int>> ManhattanMST(vector<Pt> P) {
    vector<int> id(P.size());
    iota(id.begin(),id.end(), 0);
    vector<pair<pair<int,int>, int>> edg;
    for (int k = 0; k < 4; k++) {
        sort(id.begin(),id.end(), [&](int i, int j) {return (P[i] - P[j]).x < (P[j] - P[i]).y;});
        map<int, int> sweep;
        for (int i : id) {
            auto it = sweep.lower_bound(-P[i].y);
            while (it != sweep.end()) {
                int j = it->second;
                Pt d = P[i] - P[j];
                if (d.y > d.x) break;
                edg.push_back({{i, j},d.x + d.y});
                it = sweep.erase(it);
            }
            sweep[-P[i].y] = i;
        }
        for (Pt &p : P) {
            if (k % 2) p.x = -p.x;
            else swap(p.x, p.y);
        }
    }
    return edg;
}