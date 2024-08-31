//確保兩直線P+tv和Q+tw有唯一交點且Cross(v,w)非零
Pt getLineIntersect(Line a, Line b) {
  Pt p1 = a.a, p2 = a.b, q1 = b.a, q2 = b.b;
  ld f1 = (p2-p1)^(q1-p1),f2 = (p2-p1)^(p1-q2),f;
  if(dcmp(f=f1+f2) == 0) 
    return dcmp(f1)?Pt(NAN,NAN):Pt(INFINITY,INFINITY);
  return q1*(f2/f) + q2*(f1/f);
}

//點到直線距離
double distanceToLine(Pt p,Pt a,Pt b){
    Vec v1=b-a,v2=p-a;
    return fabs(Cross(v1,v2)/Length(v1));
}

//點到線段距離
double distanceToSegment(Pt p,Pt a,Pt b){
    if(a==b) return Length(p-a);
    Vec v1=b-a,v2=p-a,v3=p-b;
    if(dcmp(Dot(v1,v2))<0) return Length(v2);
    else if(dcmp(Dot(v1,v3))>0) return Length(v3);
    else return fabs(Cross(v1,v2)/Length(v1));
}

//點到直線投影
Pt GetLineProjection(Pt p,Pt a,Pt b){
    Vec v=b-a;
    return a+v*(Dot(v,p-a)/Dot(v,v));
}

//點p於直線ab的對稱點
Pt getSymmetryPoint(Pt p,Pt a,Pt b){
    Pt q=getLineProjection(p,a,b);
    return q*2-p;
}

//判斷線段相交(剛好交一點)，若兩線段共線->c1=c2=0
bool isSegmentProperIntersection(Pt a1,Pt a2,Pt b1,Pt b2){
    double c1=Cross(a2-a1,b1-a1),c2=Cross(a2-a1,b2-a1),c3=Cross(b2-b1,a1-b1),c4=Cross(b2-b1,a2-b1);
    return dcmp(c1)*dcmp(c2)<0&&dcmp(c3)*dcmp(c4)<0;
}

//判斷線段相交(只要有交點即可)
bool isSegmentNotProperIntersection(Pt a1,Pt a2,Pt b1,Pt b2){
    return max(a1.x,a2.x)>=min(b1.x,b2.x)&&max(b1.x,b2.x)>=min(a1.x,a2.x)&&max(a1.y,a2.y)>=min(b1.y,b2.y)&&max(b1.y,b2.y)>=min(a1.y,a2.y)
    &&dcmp(Cross(a1-b1,a2-b1))*dcmp(Cross(a1-b2,a2-b2))<=0&&dcmp(Cross(b1-a1,b2-a1))*dcmp(Cross(b1-a2,b2-a2))<=0;
}

//點是否在線段上
bool isOnSegment(Pt p,Pt a1,Pt a2){
    return dcmp(Cross(a1-p,a2-p))==0&&dcmp(Dot(a1-p,a2-p))<=0;
}