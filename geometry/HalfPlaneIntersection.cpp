//O(NlgN)
// for point or line solution, change > to >=
bool onleft(Line L, Pt p) {
	return dcmp(L.v^(p-L.a)) > 0;
} // segment should add Counterclockwise
// assume that Lines intersect
// 傳入每條方程式的兩點方程式
// 回傳形成的凸多邊形頂點
// (半平面為像量 ab 的逆時針方向)
//注意題目輸入的點要是逆時針排序
vector<Pt> HPI(vector<Line>& L) {
  sort(L.begin(), L.end()); // sort by angle
  for(auto l:L){
    cerr<<l.a.x<<" "<<l.a.y<<" "<<l.b.x<<" "<<l.b.y<<" "<<l.ang<<'\n';
  }
  int n = L.size(), fir, las;
  Pt *p = new Pt[n];
  Line *q = new Line[n];
  q[fir=las=0] = L[0];
  for(int i = 1 ; i < n ; i++) {
    while(fir < las && !onleft(L[i], p[las-1])) las--;
    while(fir < las && !onleft(L[i], p[fir])) fir++;
    q[++las] = L[i];
    if(dcmp(q[las].v^q[las-1].v) == 0) {
      las--;
      if(onleft(q[las], L[i].a)) q[las] = L[i];
    }
    if(fir < las) p[las-1] = getLineIntersect(q[las-1], q[las]);
  }
  while(fir < las && !onleft(q[fir], p[las-1])) las--;
  if(las-fir <= 1) return {};
  p[las] = getLineIntersect(q[las], q[fir]);
  int m = 0;
  vector<Pt> ans(las-fir+1);
  for(int i = fir ; i <= las ; i++) ans[m++] = p[i];
  return ans;
} 