//回傳為到每個頂點距離和最小的點
Pt weiszfeld(const Pt *p,int n){
    double nn=n;
    Pt cur = p[0], next;
    for(int i=1;i<n;++i)
        cur.x+=p[i].x, cur.y+=p[i].y;
    cur.x/=nn, cur.y/=nn;
    double w,numerX,numerY,denomin;
    while(1){
        numerX=numerY=denomin=0;
        bool update=0;
        double d;
        for(int i=0;i<n;++i){
            d=Length(cur-p[i]);
            if(d>eps){
                w = 1.0/d;
                numerX+=w*p[i].x;
                numerY+=w*p[i].y;
                denomin+=w;
                update=1;
            }else{
                next = p[i];
                break;
        }   }
        if(update){
            next.x = numerX/denomin;
            next.y = numerY/denomin;
        }
        if(Length(cur-next)<eps) break;
        cur = next; 
    }
    return next;
}