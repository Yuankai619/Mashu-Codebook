//回傳{最小,最大}矩形覆蓋面積
const double INF = 1e18, qi = acos(-1) / 2 * 3;
Pt solve(vector<Pt> &dots) {
#define diff(u, v) (dots[u] - dots[v])
#define vec(v) (dots[v] - dots[i])
  hull(dots);
  ld Max = 0, Min = INF, deg;
  int n = SZ(dots);
  dots.push_back(dots[0]);
  for (int i = 0, u = 1, r = 1, l = 1; i < n; ++i) {
    Pt nw = vec(i + 1);
    while (Cross(nw, vec(u + 1)) > Cross(nw, vec(u)))
      u = (u + 1) % n;
    while (Dot(nw, vec(r + 1)) > Dot(nw, vec(r)))
      r = (r + 1) % n;
    if (!i) l = (r + 1) % n;
    while (Dot(nw, vec(l + 1)) < Dot(nw, vec(l)))
      l = (l + 1) % n;
    Min = min(Min, (double)(Dot(nw, vec(r)) - Dot(nw, vec(l))) * Cross(nw, vec(u)) / Dot(nw,nw));
    deg = acos(Dot(diff(r, l), vec(u)) / Length(diff(r, l)) / Length(vec(u)));
    deg = (qi - deg) / 2;
    Max = max(Max, Length(diff(r, l)) * Length(vec(u)) * sin(deg) * sin(deg));
  }
  return Pt(Min, Max);
}