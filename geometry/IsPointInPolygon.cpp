//判斷點是否在多邊形內部
int isPointInPolygon(Point p,Point* poly,int n){
    int wn=0;
    for(int i=0;i<n;++i){
        if(isOnSegment(p,poly[i],poly[(i+1)%n])) return -1;//在邊界上
        int k=dcmp(Cross(poly[(i+1)%n]-poly[i],p-poly[i]));
        int d1=dcmp(poly[i].y-p.y);
        int d2=dcmp(poly[(i+1)%n].y-p.y);
        if(k>0&&d1<=0&&d2>0) wn++;
        if(k<0&&d2<=0&&d1>0) wn--;
    }
    if(wn!=0) return 1;//內部
    return 0;//外部
}