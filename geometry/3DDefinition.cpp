struct Pt {
    ld x, y, z;
    Pt(ld _x = 0, ld _y = 0, ld _z = 0) : x(_x), y(_y), z(_z) {}
    Pt operator+(const Pt &a) const {
        return Pt(x + a.x, y + a.y, z + a.z);
    }
    Pt operator-(const Pt &a) const {
        return Pt(x - a.x, y - a.y, z - a.z);
    }
    Pt operator*(const ld &a) const {
        return Pt(x * a, y * a, z * a);
    }
    Pt operator/(const ld &a) const {
        return Pt(x / a, y / a, z / a);
    }
    ld operator*(const Pt &a) const {
        return x * a.x + y * a.y + z * a.z;
    }
    Pt operator^(const Pt &a) const {
        return Pt(y * a.z - z * a.y, z * a.x - x * a.z, x * a.y - y * a.x);
    }
    bool operator<(const Pt &a) const {
        return x < a.x || (x == a.x && (y < a.y || (y == a.y && z < a.z)));
    }
    bool operator==(const Pt &a) const {
        return dcmp(x - a.x) == 0 && dcmp(y - a.y) == 0 && dcmp(z - a.z) == 0;
    }
};
ld norm2(const Pt &a,const Pt &b) {return (a-b)*(a-b);}
