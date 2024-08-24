int area,in,on;//area:多邊形面積 in:內部格點數 on:邊界格點數
void PickTheorm(Point* p,int n){
    area=polygonArea(p,n);    
    for(int i=0;i<n;++i){
        on+=__gcd(abs((int)p[i].x-(int)p[(i+1)%n].x),abs((int)p[i].y-(int)p[(i+1)%n].y));
    }
    in=abs(area)+1-on/2;
}