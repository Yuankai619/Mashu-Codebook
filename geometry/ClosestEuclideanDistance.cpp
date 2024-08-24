//最近點對距離注意若整數要define double long long
double closestEuclideanDistance(Point* p,int n){
    sort(p,p+n);
    set<Point> s={{p[0].y,p[0].x}};
    int j = 0;
    Point t;
    double dd=LLONG_MAX,d;
    for(int i=1;i<n;++i){
        d = sqrt(dd);
        while(j<i && p[j].x < p[i].x-d){
            s.erase({p[j].y,p[j++].x});
        }
        auto l = s.lower_bound({p[i].y-d,p[i].x-d});
        auto u = s.upper_bound({p[i].y+d,p[i].x+d});
        for(auto it=l;it!=u;it++){
            t = {it->y,it->x};
            dd =min(dd, Dot(p[i]-t,p[i]-t));
        }  
        s.emplace(p[i].y,p[i].x); 
    }
    return dd;
}