#define SZ 1000
using namespace std;
typedef pair<int,int> ii;
typedef deque<ii> dii;

double PI=acos(-1);
double iiabs(ii a){return sqrt(a.x*a.x+a.y*a.y);}
ii operator-(ii a,ii b){return ii(a.x-b.x,a.y-b.y);}
double dist(ii a,ii b){return iiabs(a-b);}
double ang(ii a){return atan2(a.y,a.x);}
double cot(double i){while(i<=-PI) i+=2*PI; while(i>PI) i-=2*PI; return i;}
int rcw(ii a0, ii a1, ii a2){
	int result = (a2.x - a1.x)*(a0.y-a1.y) - (a2.y-a1.y)*(a0.x-a1.x);
	if (result < 0) return -1;
	if (result > 0) return 1;
	return 0;
}
double deg(double i){return i*180/PI;}
bool intls(ii l0,ii l1,ii s0,ii s1){return ccw(l0,l1,s0)*ccw(l0,l1,s1)!=1;}
bool intss(ii a0,ii a1,ii b0,ii b1){
  if(ccw(a0,a1,b0)>=0&&ccw(a0,a1,b1)<=0&&ccw(b0,b1,a0)<=0&&ccw(b0,b1,a1)>=0) return true;
  if(ccw(a0,a1,b0)<=0&&ccw(a0,a1,b1)>=0&&ccw(b0,b1,a0)>=0&&ccw(b0,b1,a1)<=0) return true;
  return false;
}
bool intlp(ii l0,ii l1,ii a){ return ccw(l0,l1,a)==0;}
bool intsp(ii s0,ii s1,ii a){ return dist(s0,s1)==dist(s0,a)+dist(a,s1);}
double ccwang(ii a,ii b,ii c){ c=c-b; b=b-a; return cot(ang(c)-ang(b));}
double insang(ii a,ii b,ii c){ return PI-abs(ccwang(a,b,c));}
double distlp(ii l0,ii l1,ii a){
	ii d=l1-l0;
	return abs(d.y*a.x-d.x*a.y-l0.x*l1.y+l1.x*l0.y)/(double)iiabs(d);
}
double distsp(ii s0,ii s1,ii a){
	if(insang(s0,s1,a)<=PI/2 && insang(s1,s0,a)<=PI/2) return distlp(s0,s1,a);
	return min(dist(a,s0),dist(a,s1));
}
bool inpol(dii &pol,ii a){
	int polsz=(int)pol.size(),wn=0,i;
	pol.pb(pol[0]);
	loop(i,0,polsz)
		if(pol[i].y <=a.y){	if(pol[i+1].y>a.y && ccw(a,pol[i],pol[i+1])==1) wn++; }
		else if(pol[i+1].y<=a.y && ccw(a,pol[i],pol[i+1])==-1) wn--;
	pol.popb();
	return !(wn==0);
}
// Expected: 4800 6818 1668 5723 8662 3530
int h,mod=11311,a=929,sz=700;
ii p[SZ];
dii pol;
int prandom(int b){return h=(a*h+abs(b))%mod;}
int ftest(int i,int j){
	if(j==0) return intls(p[i],p[i+1],p[i+2],p[i+3]);
	if(j==1) return intss(p[i],p[i+1],p[i+2],p[i+3]);
	if(j==2) return distlp(p[i],p[i+1],p[i+2]);
	if(j==3) return distsp(p[i],p[i+1],p[i+2]);
	if(j==4) return inpol(pol,p[i]);
}
int main(){
	int i,j;
	h=0;
	loop(i,0,sz+3) p[i]=ii(prandom(137),prandom(137));
  printf("%d\n",h);
  pol.clear(); loop(i,0,sz/7) pol.pb(p[i]);
  loop(j,0,5){
		h=0;
		loop(i,0,sz) prandom(i+ftest(i,j));
		printf("%d\n",h);
	}
	return 0;
}
