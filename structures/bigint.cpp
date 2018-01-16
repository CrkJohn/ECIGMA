#define Base 10000
#define SZ 1000005

typedef long long int large;
typedef vector<large> bigint;
int aa[SZ],ab[SZ],ac[SZ];

bigint bbsum(bigint &a,bigint &b){
	int i,ca=0;
	bigint c;
	loop(i,0,a.size()){ c.pushb((a[i]+b[i]+ca)%Base); ca=(a[i]+b[i]+ca)/Base; }
	loop(i,a.size(),b.size()){ c.pushb((b[i]+ca)%Base); ca=(b[i]+ca)/Base; }
	if(ca>0) c.pushb(ca);
	return c;
}

bigint operator+(bigint &a,bigint &b){return a.size()<=b.size()?bbsum(a,b):bbsum(b,a);} 

bigint operator*(bigint &a,bigint &b){ // n*n
  int i,j,csz=a.size()+b.size();
  setmem(ac,0);
  loop(i,0,a.size()) loop(j,0,b.size()) ac[i+j]+=a[i]*b[j];
  loop(i,0,csz){
  	ac[i+1] += ac[i]/Base;
    ac[i] %= Base;
  }
  while(csz>0 && ac[csz-1]==0) csz--;
  bigint c;
  loop(i,0,csz) c.pushb(ac[i]);
  return c;
}

bigint operator*(bigint &a,bigint &b){ // n log n
  int i;
  loop(i,0,a.size()) aa[i]=a[i];
  loop(i,0,b.size()) ab[i]=b[i];
  int csz=polymult(aa,ab,ac,a.size(),b.size()); // see docs.
  loop(i,0,csz){
  	ac[i+1] += ac[i]/Base;
    ac[i] %= Base;
  }
  while(csz>0 && ac[csz-1]==0) csz--;
  bigint c;
  loop(i,0,csz) c.pushb(ac[i]);
  return c;
}

void printbigint(bigint &a){
	int i,z=log10(Base);
	char s[10];
	sprintf(s,"%%0%dlld",z);
	if(a.size()>0){
		printf("%lld",a[a.size()-1]);
		rev(i,a.size()-2,0) printf(s,a[i]);
	} else printf("0");
	printf("\n");
}