Pt inCenter( Pt &A,  Pt &B,  Pt &C) { // 内心
	double a = Dot(B-C,B-C), b = Dot(C-A,C-A), c = Dot(A-B,A-B);
	return (A * a + B * b + C * c) / (a + b + c);
}
Pt circumCenter( Pt &a,  Pt &b,  Pt &c) { // 外心
	Pt bb = b - a, cc = c - a;
	double db=Length(bb), dc=Length(cc), d=2*(bb ^ cc);
	return a-Pt(bb.y*dc-cc.y*db, cc.x*db-bb.x*dc) / d;
}
Pt othroCenter( Pt &a,  Pt &b,  Pt &c) { // 垂心
	Pt ba = b - a, ca = c - a, bc = b - c;
	double y = ba.y * ca.y * bc.y,
	  A = ca.x * ba.y - ba.x * ca.y,
	  x0= (y+ca.x*ba.y*b.x-ba.x*ca.y*c.x) / A,
	  y0= -ba.x * (x0 - c.x) / ba.y + ca.y;
	return Pt(x0, y0);
}