//定義：給兩點集合A,B，Minkowski Sum是A+B={a+b|a∈A,b∈B}的凸包
//視覺化為一個凸包 A 繞著凸包 B 轉一圈，O(N)
//兩個凸多邊形的 Minkowski sum，也會是凸多邊形
//P 和 Q 組成的 Minkowski sum 最多有 |P|+|Q| 個點
//在凸包 A 和 B 上的邊也會在 Minkowski sum 上出現
//傳入的點集合不用逆時針排序
vector<Pt> Minkowski(vector<Pt> A, vector<Pt> B) { // |A|,|B|>=3
  hull(A), hull(B);
  vector<Pt> C(1, A[0] + B[0]), s1, s2; 
  for (int i = 0; i < SZ(A); ++i) s1.push_back(A[(i + 1) % SZ(A)] - A[i]);
  for (int i = 0; i < SZ(B); i++) s2.push_back(B[(i + 1) % SZ(B)] - B[i]);
  for (int i = 0, j = 0; i < SZ(A) || j < SZ(B);)
    if (j >= SZ(B) || (i < SZ(A) && Cross(s1[i], s2[j]) >= 0)) C.push_back(B[j % SZ(B)] + A[i++]);
    else C.push_back(A[i % SZ(A)] + B[j++]);
  return hull(C), C;
}