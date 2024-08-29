#define ld long double
const ld eps=1e-10;
int dcmp(ld x){if(fabs(x)<eps) return 0;else return x<0?-1:1;}
struct Pt{
    ld x,y;
    Pt(ld x=0,ld y=0):x(x),y(y){}
    Pt operator+(const Pt &a) const {
        return Pt(x+a.x, y+a.y);  }
    Pt operator-(const Pt &a) const {
        return Pt(x-a.x, y-a.y);  }
    Pt operator*(const ld &a) const {
        return Pt(x*a, y*a);  }
    Pt operator/(const ld &a) const {
        return Pt(x/a, y/a);  }
    ld operator*(const Pt &a) const {//dot
        return x*a.x + y*a.y;  }
    ld operator^(const Pt &a) const {//cross
        return x*a.y - y*a.x;  }
    bool operator<(const Pt &a) const {
        return x < a.x || (x == a.x && y < a.y); }
        //return dcmp(x-a.x) < 0 || (dcmp(x-a.x) == 0 && dcmp(y-a.y) < 0); }
    bool operator>(const Pt &a) const {
        return x > a.x || (x == a.x && y > a.y); }
        //return dcmp(x-a.x) > 0 || (dcmp(x-a.x) == 0 && dcmp(y-a.y) > 0); }
    bool operator==(const Pt &a) const {
        return dcmp(x-a.x) == 0 && dcmp(y-a.y) == 0;  }
        // return x == other.x && y == other.y;
};
typedef Pt Vec;
ld Dot(Vec a,Vec b){return a.x*b.x+a.y*b.y;}
ld Cross(Vec a,Vec b){return a.x*b.y-a.y*b.x;}
ld Length(Vec a){return sqrt(Dot(a,a));}

ld Angle(Vec a,Vec b){return acos(Dot(a,b)/Length(a)/Length(b));}//弧度
ld Degree(Vec a,Vec b){return Angle(a,b)*180/acos(-1);}//角度
ld Area2(Pt a,Pt b,Pt c){return Cross(b-a,c-a);}//(a,b)X(a,c)的面積 
Vec Rotate(Vec a,ld rad){return Vec(a.x*cos(rad)-a.y*sin(rad),a.x*sin(rad)+a.y*cos(rad));}//逆時針旋轉,rad為弧度
Vec Normal(Vec a){ld L=Length(a);return Vec(-a.y/L,a.x/L);}//單位法向量，確保a不是零向量    

struct Line {
  Pt a, b, v; // start, end, end-start
  ld ang;
  Line(Pt _a=Pt(0, 0), Pt _b=Pt(0, 0)):a(_a),b(_b) { v = b-a; ang = atan2(v.y, v.x); }
  bool operator<(const Line &L) const {
    return ang < L.ang;
} };