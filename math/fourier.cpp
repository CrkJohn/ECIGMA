#define SZ 1000005 

using namespace std;
typedef complex<double> im;

double PI=acos(-1);

im p[SZ],u[SZ],v[SZ],ima[SZ],imb[SZ],imc[SZ];

void fft(im* p, im* u, im* v, int n){
	if(n==1) return;
	int i; im w=1, wn=exp((im)(-2j*PI/n));
	n=n/2;
	loop(i,0,n) u[i]=p[2*i], v[i]=p[2*i+1];
	fft(u,u+n,v+n,n);
	fft(v,u+n,v+n,n);
	loop(i,0,2*n){ p[i]=(u[i%n]+w*v[i%n]); w=w*wn; }
}

void ifft(im* p, im* u, im* v, int n){
	int i;
	loop(i,0,n) p[i]=conj(p[i]);
	fft(p,u,v,n);
	loop(i,0,n) p[i]=conj(p[i])/(im)n;
}

int polymult(int* a, int* b,int* c, int asz, int bsz){
	int csz= pow(2,ceil(log(asz+bsz)/log(2)));
	int i;
	memset(ima,0,csz*16); // im uses 16 bytes
	memset(imb,0,csz*16);
	loop(i,0,asz) ima[i] = a[i];
	loop(i,0,bsz) imb[i] = b[i];
	fft(ima,u,v,csz);
	fft(imb,u,v,csz);
	loop(i,0,csz) imc[i] = ima[i]*imb[i];
	ifft(imc,u,v,csz);
	loop(i,0,csz) c[i] = (int)round(real(imc[i]));
	return csz;
}
