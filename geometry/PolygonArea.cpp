//須注意long long 及 加上絕對值
double polygonArea(Point* p,int n){
    double area=0;
    for(int i=1;i<n-1;++i){
        area+=Cross(p[i]-p[0],p[i+1]-p[0]);
    }
    return area/2;
}