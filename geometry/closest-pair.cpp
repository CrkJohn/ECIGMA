ii vec[LIM];
int n;

double dist_sq(ii a, ii b){
	return ((a.X-b.X)*(a.X-b.X)+(a.Y-b.Y)*(a.Y-b.Y));
}

int main(void){
  int i, j;
  double res;
  setvbuf(stdin, NULL, _IOFBF, 1<<18);
  setvbuf(stdout, NULL, _IOFBF, 1<<18);
  //READ("TheClosestPairProblem10245.txt");
  while (scanf("%d", &n)==1 && n>0){
    FOR(i, 0, n) scanf("%lf %lf", &(vec[i].X), &(vec[i].Y));
    if (n<2){
      puts("INFINITY");
      continue;
    }
    sort(vec, vec+n);
    res=1.0*INF*INF;
    FOR(i, 1, n){
      REV(j, i-1, 0){
        if ((vec[i].X-vec[j].X)*(vec[i].X-vec[j].X)>=res) break;
        if (dist_sq(vec[i], vec[j])<res){
          res=dist_sq(vec[i], vec[j]);
        }
      }
    }
    res=sqrt(res);
    if (res>10000.0) puts("INFINITY");
    else printf("%.4lf\n", res);
  }
  return 0;
}