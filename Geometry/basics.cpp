
typedef complex<double> point;
typedef vector<point> polygon;

#define NEXT(i) (((i) + 1) % n)


struct circle{
     point c ; double r;
     circle(){point c = point(0.,0.); double r=0.0;}
     circle(point _c, double _r): c(_c.x,_c.y), r(_r){}
};

struct line { point p, q; };
using segment = line;

const double eps = 1e-9;

// fix comparations on doubles with this two functions
int sign(double x) { return x < -eps ? -1 : x > eps; }

int dblcmp(double x, double y) { return sign(x - y); }

double dot(point a, point b) { return real(conj(a) * b); }

double cross(point a, point b) { return imag(conj(a) * b); }

double area2(point a, point b, point c) { return cross(b - a, c - a); }

int ccw(point a, point b, point c)
{
	b -= a; c -= a;
	if (cross(b, c) > 0) return +1; // counter clockwise
	if (cross(b, c) < 0) return -1; // clockwise
	if (dot(b, c) < 0) return +2; // c--a--b on line
	if (dot(b, b) < dot(c, c)) return -2; // a--b--c on line
	return 0;
}

namespace std
{
	bool operator<(point a, point b)
	{
		if (a.real() != b.real())
			return a.real() < b.real();
		return a.imag() < b.imag();
	}
}

struct point { 
	double x, y;
  	point() { x = y = 0.0; }
  	point(double _x, double _y) : x(_x), y(_y) {}        
  	bool operator == (point other) const {
   		return (fabs(x - other.x) < 1e-9 && (fabs(y - other.y) < 1e-9)); 
   	}
};


/*Trabajando con estructuras de tipo punto*/
  double euclideanDistance(point p1, point p2) {           
    return hypot(p1.x - p2.x, p1.y - p2.y); 
  } 

/*Trabajando con los valores x y y de cada punto*/
double euclideanDistance(double x1, double y1, double x2, double y2){           
  return hypot(x1 - x2, y1 - y2); 
} 



Dados dos puntos A y B, crea el vector A->B. IMPORTANTE: Debe definirse la estructura point. Es llamado vec para no confundirlo con el vector propio de c++.
struct vec { 
	double x, y;  
  vec(double _x, double _y) : x(_x), y(_y) {} 
};

vec toVector(point a, point b) {       
	return vec(b.x - a.x, b.y - a.y); 
}

