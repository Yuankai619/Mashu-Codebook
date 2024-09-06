//給兩多邊形，求最短距離
double PolyDist(vector<Pt> A, vector<Pt> B) {
    for (auto &p : B) p = {-p.x, -p.y};
    auto C = Minkowski(A, B); // assert SZ(C) > 0
    if (isPointInPolygon(Pt{},C.data(),C.size())) return 0;
    double ans = distanceToSegment(Pt{},C.back(), C[0]);
    for (int i = 0; i + 1 < SZ(C); ++i)
        ans = min(ans, distanceToSegment(Pt{},C[i], C[i + 1]));
    return ans;
}