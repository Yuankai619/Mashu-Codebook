// O(N) Minimum enclosing circle
struct Mec{  // return pair of center and r
  int n;
  Pt p[ MXN ], cen;
  double r2;  
  void init( int _n , Pt _p[] ){
    n = _n;
    memcpy( p , _p , sizeof(Pt) * n );
  }
  double sqr(double a){ return a*a; }
  Pt center(Pt p0, Pt p1, Pt p2) {
    Pt a = p1-p0;
    Pt b = p2-p0;
    double c1=Dot(a,a) * 0.5;
    double c2=Dot(b,b) * 0.5;
    double d = a ^ b;
    double x = p0.x + (c1 * b.y - c2 * a.y) / d;
    double y = p0.y + (a.x * c2 - b.x * c1) / d;
    return Pt(x,y);
  }
  pair<Pt,double> solve(){
    random_shuffle(p,p+n); r2=0;
    for (int i=0; i<n; i++){
      if (Dot(cen-p[i],cen-p[i]) <= r2) continue;
      cen = p[i];
      r2 = 0;
      for (int j=0; j<i; j++){
        if (Dot(cen-p[j],cen-p[j]) <= r2) continue;
        cen=Pt((p[i].x+p[j].x)/2,(p[i].y+p[j].y)/2);
        r2 = Dot(cen-p[j],cen-p[j]);
        for (int k=0; k<j; k++){
          if (Dot(cen-p[k],cen-p[k]) <= r2) continue;
          cen = center(p[i],p[j],p[k]);
          r2 = Dot(cen-p[k],cen-p[k]);
    } } }
    return {cen,sqrt(r2)};
} }mec;