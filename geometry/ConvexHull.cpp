//回傳凸包頂點數
//輸入不能有重複點，注意h的點未排序!
//如果有在邊上的輸入點，要把<=改成< 
//若要求高精度用dcmp比較
vector<Pt> ch(MXN);
int convexHull(Pt* p,int n){
    sort(p,p+n);
    int m=0;
    for(int i=0;i<n;++i){//downHull
        while(m>1&&Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0) m--;
        ch[m++]=p[i];
    }
    int k=m;
    for(int i=n-2;i>=0;--i){//upHull
        while(m>k&&Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0) m--;
        ch[m++]=p[i];
    }
    if(n>1) m--;
    return m;
}