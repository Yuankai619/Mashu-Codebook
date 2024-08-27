struct Point{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
    bool operator==(const Point &other) const {
        return x == other.x && y == other.y;
    }
};
typedef Point Vector;
Vector operator + (Vector a,Vector b){return Vector(a.x+b.x,a.y+b.y);}
Vector operator - (Vector a,Vector b){return Vector(a.x-b.x,a.y-b.y);}
Vector operator * (Vector a,double p){return Vector(a.x*p,a.y*p);}
Vector operator / (Vector a,double p){return Vector(a.x/p,a.y/p);}
const double eps=1e-10;
int dcmp(double x){if(fabs(x)<eps) return 0;else return x<0?-1:1;}
//bool operator == (const Point& a,const Point& b){return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0;}//高精度
bool operator < (const Point& a,const Point& b){return a.x<b.x||(a.x==b.x&&a.y<b.y);}
bool operator > (const Point& a,const Point& b){return a.x>b.x||(a.x==b.x&&a.y>b.y);}
double Dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}
double Cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
double Length(Vector a){return sqrt(Dot(a,a));}

double Angle(Vector a,Vector b){return acos(Dot(a,b)/Length(a)/Length(b));}//弧度
double Degree(Vector a,Vector b){return Angle(a,b)*180/acos(-1);}//角度
double Area2(Point a,Point b,Point c){return Cross(b-a,c-a);}//(a,b)X(a,c)的面積 
Vector Rotate(Vector a,double rad){return Vector(a.x*cos(rad)-a.y*sin(rad),a.x*sin(rad)+a.y*cos(rad));}//逆時針旋轉,rad為弧度
Vector Normal(Vector a){double L=Length(a);return Vector(-a.y/L,a.x/L);}//單位法向量，確保a不是零向量
