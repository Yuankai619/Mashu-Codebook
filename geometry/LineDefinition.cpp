struct Line {
  Pt a, b, v; // start, end, end-start
  ld ang;
  Line(Pt _a=Pt(0, 0), Pt _b=Pt(0, 0)):a(_a),b(_b) { v = b-a; ang = atan2(v.y, v.x); }
  bool operator<(const Line &L) const {
    return ang < L.ang;
} };
int PtSide(Pt p, Line L) {//return 1:左側 0:線上 -1:右側
    return Sgn(Ori(L.a, L.b, p));
}
bool PtOnSeg(Pt p, Line L) {//點是否在線段上
    return Sgn(Ori(L.a, L.b, p)) == 0 && Sgn((p - L.a) * (p - L.b)) <= 0;
}
Pt Proj(Pt p, Line l) {//點到線段的投影點
    Pt dir = Unit(l.b - l.a);
    return l.a + dir * (dir * (p - l.a));
}
bool isInter(Line l, Line m) {//判斷兩線段是否相交
    if (PtOnSeg(m.a, l) || PtOnSeg(m.b, l) ||
        PtOnSeg(l.a, m) || PtOnSeg(l.b, m))
        return true;
    return PtSide(m.a, l) * PtSide(m.b, l) < 0 &&
           PtSide(l.a, m) * PtSide(l.b, m) < 0;
}
Pt LineInter(Line l, Line m) {//兩線段交點
    double s = Ori(m.a, m.b, l.a), t = Ori(m.a, m.b, l.b);
    return (l.b * s - l.a * t) / (s - t);
}