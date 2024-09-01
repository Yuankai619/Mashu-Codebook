//極角排序，從270度開始逆時針排序
bool cmp(const Pt& lhs,const Pt&rhs){
    if(Cross((lhs < Pt()),(rhs < Pt())))
        return (lhs < Pt()) < (rhs < Pt());
    return Cross(lhs,rhs) > 0;
}
/* 若要以p[i]為原點排序->計算v=p[j]-p[i]
for(int j=0;j<n;++j){
    if(i!=j){
        Vector v = p[j]-p[i];
        node[nodeSz++] = {v,j};
    }
}
sort(node,node+nodeSz,cmp);
*/