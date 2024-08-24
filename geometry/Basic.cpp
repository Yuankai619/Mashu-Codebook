getLineIntersection
//確保兩直線P+tv和Q+tw有唯一交點且Cross(v,w)非零
Point getLineIntersection(Point P,Vector v,Point Q,Vector w){
    Vector u=P-Q;
    double t=Cross(w,u)/Cross(v,w);
    return P+v*t;
}

distanceToLine
//點到直線距離
double distanceToLine(Point p,Point a,Point b){
    Vector v1=b-a,v2=p-a;
    return fabs(Cross(v1,v2)/Length(v1));
}

distanceToSegment
//點到線段距離
double distanceToSegment(Point p,Point a,Point b){
    if(a==b) return Length(p-a);
    Vector v1=b-a,v2=p-a,v3=p-b;
    if(dcmp(Dot(v1,v2))<0) return Length(v2);
    else if(dcmp(Dot(v1,v3))>0) return Length(v3);
    else return fabs(Cross(v1,v2)/Length(v1));
}

GetLineProjection
//點到直線投影
Point GetLineProjection(Point p,Point a,Point b){
    Vector v=b-a;
    return a+v*(Dot(v,p-a)/Dot(v,v));
}

getSymmetryPoint
//點p於直線ab的對稱點
Point getSymmetryPoint(Point p,Point a,Point b){
    Point q=getLineProjection(p,a,b);
    return q*2-p;
}

isSegmentProperIntersection
//判斷線段相交(剛好交一點)，若兩線段共線->c1=c2=0
bool isSegmentProperIntersection(Point a1,Point a2,Point b1,Point b2){
    double c1=Cross(a2-a1,b1-a1),c2=Cross(a2-a1,b2-a1),c3=Cross(b2-b1,a1-b1),c4=Cross(b2-b1,a2-b1);
    return dcmp(c1)*dcmp(c2)<0&&dcmp(c3)*dcmp(c4)<0;
}

isSegmentNotProperIntersection
//判斷線段相交(只要有交點即可)
bool isSegmentNotProperIntersection(Point a1,Point a2,Point b1,Point b2){
    return max(a1.x,a2.x)>=min(b1.x,b2.x)&&max(b1.x,b2.x)>=min(a1.x,a2.x)&&max(a1.y,a2.y)>=min(b1.y,b2.y)&&max(b1.y,b2.y)>=min(a1.y,a2.y)
    &&dcmp(Cross(a1-b1,a2-b1))*dcmp(Cross(a1-b2,a2-b2))<=0&&dcmp(Cross(b1-a1,b2-a1))*dcmp(Cross(b1-a2,b2-a2))<=0;
}

isOnSegment
//點是否在線段上
bool isOnSegment(Point p,Point a1,Point a2){
    return dcmp(Cross(a1-p,a2-p))==0&&dcmp(Dot(a1-p,a2-p))<=0;
}