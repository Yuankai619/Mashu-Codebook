//rotate(begin(s),begin(s)+minRotation(s),end(s))
//For example,rotations of acab are acab, caba, abac, and baca.
//find lexicographically minimal rotation of a string
int minRotation(string s) {
  int a = 0, N = s.size(); s += s;
  for(int b=0;b<N;b++) for(int k=0;k<N;k++) {
    if(a+k == b || s[a+k] < s[b+k])
      {b += max(0, k-1); break;}
    if(s[a+k] > s[b+k]) {a = b; break;}
  } return a;
}