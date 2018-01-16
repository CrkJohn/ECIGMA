typedef struct { int m[LEN][LEN];} matrix;
matrix m, m2;

#define WIDTH 31
#define GWIDTH 5
large za[LEN][GWIDTH],zb[LEN][GWIDTH];

void operator*=(matrix &a ,matrix& b){
	int u,v,j;
	loop(u,0,V){
		loop(j,0,GWIDTH) za[u][j]=0;
		loop(v,0,V) za[u][v/WIDTH] |= (a.m[u][v]) << (v%WIDTH);
	}
	loop(v,0,V){
		loop(j,0,GWIDTH) zb[v][j]=0;
		loop(u,0,V) zb[v][u/WIDTH] |= (b.m[u][v]) << (u%WIDTH);
	}
	loop(u,0,V) loop(v,0,V){
		a.m[u][v] = 0;
		loop(j,0,GWIDTH) a.m[u][v] |= ((za[u][j] & zb[v][j])!=0);
	}
}

void matcpy(matrix& a, matrix& b){
	int u,v;
	loop(u,0,V) loop(v,0,V) b.m[u][v]=a.m[u][v];
}

void mpow(int n){
	matcpy(m,m2);
	int u,v;
	loop(u,0,V)	loop(v,0,V) m.m[u][v]=(u==v);
	while(n){
		if(n%2)	m*=m2;
		m2*=m2,	n/=2;
	}
}