#define ld long double
const ld eps=1e-10;
int dcmp(ld x){if(fabs(x)<eps) return 0;else return x<0?-1:1;}
struct Pt{
    ld x,y;
    Pt(ld x=0,ld y=0):x(x),y(y){}
    Pt operator+(const Pt &a) const {return Pt(x+a.x, y+a.y);}
    Pt operator-(const Pt &a) const {return Pt(x-a.x, y-a.y);}
    Pt operator*(const ld &a) const {return Pt(x*a, y*a);}
    Pt operator/(const ld &a) const {return Pt(x/a, y/a);}
    ld operator*(const Pt &a) const {return x*a.x + y*a.y;} //dot
    ld operator^(const Pt &a) const {return x*a.y - y*a.x;} //cross
    bool operator<(const Pt &a) const {return x < a.x || (x == a.x && y < a.y);}
        //return dcmp(x-a.x) < 0 || (dcmp(x-a.x) == 0 && dcmp(y-a.y) < 0); }
    bool operator>(const Pt &a) const {return x > a.x || (x == a.x && y > a.y);}
        //return dcmp(x-a.x) > 0 || (dcmp(x-a.x) == 0 && dcmp(y-a.y) > 0); }
    bool operator==(const Pt &a) const {return dcmp(x-a.x) == 0 && dcmp(y-a.y) == 0;}
        // return x == other.x && y == other.y;
     bool operator!=(const Pt &a) const {return !(*this == a);}
};
typedef Pt Vec;
ld Dot(Vec a,Vec b){return a.x*b.x+a.y*b.y;}
ld Cross(Vec a,Vec b){return a.x*b.y-a.y*b.x;}
ld Length(Vec a){return sqrt(Dot(a,a));}
int Sgn(double x){ return (x > -eps) - (x < eps); }//return 0: x==0, 1: x>0, -1: x<0
ld Angle(Vec a,Vec b){return acos(Dot(a,b)/Length(a)/Length(b));}//弧度
ld Degree(Vec a,Vec b){return Angle(a,b)*180/acos(-1);}//角度
ld Ori(Pt a,Pt b,Pt c){return Cross(b-a,c-a);}//1.(a,b)x(a,c)的面積  2. a在bc左側>0 3. a在bc右側<0 4. a在bc上==0
Vec Rotate(Vec a,ld rad){return Vec(a.x*cos(rad)-a.y*sin(rad),a.x*sin(rad)+a.y*cos(rad));}//逆時針旋轉,rad為弧度
Vec Normal(Vec a){ld L=Length(a);return Vec(-a.y/L,a.x/L);}//單位法向量，確保a不是零向量    
Vec Unit(Vec x) { return x / Length(x); } //單位向量
Vec Perp( const Vec v ){ return { v.y , -v.x };}//垂直向量
bool argcmp(const Pt &a, const Pt &b) { // 極角cmp: arg(a) < arg(b)
    int f = (Pt{a.y, -a.x} > Pt{} ? 1 : -1) * (a != Pt{});
    int g = (Pt{b.y, -b.x} > Pt{} ? 1 : -1) * (b != Pt{});
    return f == g ? (a ^ b) > 0 : f < g;
}
struct Circle {
  Pt o; ld r;
  Circle(Pt _o=Pt(0, 0), ld _r=0):o(_o), r(_r) {}
};