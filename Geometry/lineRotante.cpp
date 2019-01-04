#include<bits/stdc++.h>
#define loop(i,a,b) for(int i = a; i<b;i++)
#define FOR(i,b) for(int i = 0; i<b;i++)
#define forn(i,a,b) for(int i = a; i<=b;i++)
#define pb push_back
#define fi first
#define se second
#define eps 1e-9
#define INF 1e9


using namespace std;

double dot(point a , point b) { return real(conj(a)*b); }
double cross(point a , point b){ return imag(conj(a)*b); }

bool arg_cmp(point a, point b){ return arg(a) < arg(b); }

bool isizq(point a, point b){return cross(a, b)>eps; }
bool isder(point a, point b){return isizq(b,a); }
bool iseq(point a, point b){
    double x=abs(arg(a)-arg(b));
    return x<=eps || abs(2*pi-x)<=eps;
}

void rotating_divider(
        const vector<point> a,
        vector<int> &D,
        vector<int> &I,
        vector<int> &R,
        vector<int> &X){
    //Requiere:
    // + Vector de puntos ordenandos por arg, sin orígenes
    //Retorna: [O(n)]
    // + D[i] = # de puntos a la derecha (estricta) del rayo 0 -> a[i]
    // + I[i] = # de puntos a la izquierda (estricta) del rayo 0 -> a[i]
    // + R[i] = # de puntos sobre el rayo 0 -> a[i]
    // + X[i] = # de puntos sobre el rayo 0 -> (-a[i])

    int n=len(a);
    // Assert:
    loop(i,0,n-1) assert(arg(a[i])<=arg(a[i+1])); // a is sorted by arg
    loop(i,0,n) assert(abs(a[i])>eps); // no origins in a
    // Prepare:
    D.resize(n);
    I.resize(n);
    R.resize(n);
    X.resize(n);
    if(n==0) return;
    // Find opposite index of each point:
    vector<int> op(n);
    for(int j=0, k=0; j<n; j++){
        if(k==j) k=(k+1)%n;
        while(k!=j && iseq(a[j], a[k])) k=(k+1)%n;
        while(k!=j && isizq(a[j], a[k])) k=(k+1)%n;
        op[j] = k;
    }
    // Compute D (and partially R):
    D[0]=0;
    loop(i,0,n) if(isder(a[0], a[i])) D[0]++;
    R[0]=1;
    loop(i,1,n){
        D[i] = D[i-1];
        if(iseq(a[i], a[i-1])) R[i]=R[i-1]+1;
        else R[i]=1;
        if(isder(a[i], a[i-1])) D[i]+=R[i-1];
        int j = op[i-1];
        if(i==j) j=(j+1)%n;
        while(!isder(a[i], a[j])){
            if(isder(a[i-1], a[j])) D[i]--;
            if(j==i) break;
            j = (j+1)%n;
        }
    }
    // Compute R, X and I:
    loop(i,0,n) X[i] = R[i];
    rev(i,n-2,0) R[i] = X[i+1]==X[i]+1? R[i+1]:X[i];
    loop(i,0,n) X[i] = iseq(a[i], -a[op[i]])? R[op[i]]:0;
    loop(i,0,n) I[i] = n-D[i]-R[i]-X[i];
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;


	return 0;
}




