//若要求高精度用dcmp比較
//若是搞int點要記得定義改int
//輸入不能有重複點，注意h的點未排序!
//若需保留共線點，把while裡的Ori判斷式改成<=0
void hull(vector<Pt> &dots) { // n=1 => ans = {}
  sort(dots.begin(), dots.end());
  vector<Pt> ans(1, dots[0]);
  for (int ct = 0; ct < 2; ++ct, reverse(all(dots)))
    for (int i = 1, t = SZ(ans); i < SZ(dots); ans.push_back(dots[i++]))
      while (SZ(ans) > t && Ori(ans[SZ(ans) - 2], ans.back(), dots[i]) <= 0) 
        ans.pop_back();
  ans.pop_back(), ans.swap(dots);
}
