// mat t(r,c);
struct mat{
    long long a[200][200],r,c; // resize
    mat(int _r,int _c){r=_r;c=_c;memset(a,0,sizeof(a));}
    void build(){for(int i=0;i<r;++i)a[i][i]=1;} // 單位矩陣
};
mat operator * (mat x,mat y){
    mat z(x.r,y.c);
    for(int i=0;i<x.r;++i)for(int j=0;j<x.c;++j)for(int k=0;k<y.c;++k)
        z.a[i][j]=(z.a[i][j]+x.a[i][k]*y.a[k][j]%MOD)%MOD;
    return z;
}
mat matpow(mat a,int k){
    mat r(a.r,a.r);r.build();while(k){if(k&1)r=r*a;a=a*a;k>>=1;}return r;
}
