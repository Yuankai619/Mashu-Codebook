//極角排序，從270度開始逆時針排序
bool cmp(const Point& lhs,const Point&rhs){
    if(Cross((lhs < Point()),(rhs < Point())))
        return (lhs < Point()) < (rhs < Point());
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