#include <bits/stdc++.h>
#define FOR(i, a, b)   for(i=a; i<b; i++)
#define LIM            205
#define SET(mat, a)    memset(mat, a, sizeof(mat))
#define X              first
#define Y              second
#define mp             make_pair
#define pb             push_back
#define INF            10000000
using namespace std;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<int> VI;
typedef pair<int, int> ii;
typedef long long      ll;
double cost[LIM][LIM];
VI Lmate, Rmate;
int n, r;

double MinCostMatching() {
//int n=int(cost.size()); //construct dual feasible solution
  int i, j;
  VD u(n);
  VD v(n);
  for (i = 0; i < n; i++) {
    u[i] = cost[i][0];
    for (j = 1; j < n; j++) u[i] = min(u[i], cost[i][j]);
  }
  for (j = 0; j < n; j++) {
    v[j] = cost[0][j] - u[0];
    for (i=1; i<n; i++) v[j] = min(v[j], cost[i][j]-u[i]);
  }
//construct primal solution satisfying complementary slackness
  Lmate = VI(n, -1);
  Rmate = VI(n, -1);
  int mated = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (Rmate[j] != -1) continue;
      if (fabs(cost[i][j] - u[i] - v[j]) < 1e-10) {
        Lmate[i] = j;
        Rmate[j] = i;
        mated++;
        break;
      }
    }
  }
  
  VD dist(n);
  VI dad(n);
  VI seen(n);
  // repeat until primal solution is feasible
  while (mated < n) {
    // find an unmatched left node
    int s = 0;
    while (Lmate[s] != -1) s++;
    // initialize Dijkstra
    fill(dad.begin(), dad.end(), -1);
    fill(seen.begin(), seen.end(), 0);
    for (int k = 0; k < n; k++) 
      dist[k] = cost[s][k] - u[s] - v[k];
    
    j = 0;
    while (true) {
      // find closest
      j = -1;
      for (int k = 0; k < n; k++) {
        if (seen[k]) continue;
        if (j == -1 || dist[k] < dist[j]) j = k;
      }
      seen[j] = 1;
      // termination condition
      if (Rmate[j] == -1) break;
      // relax neighbors
      i = Rmate[j];
      for (int k = 0; k < n; k++) {
        if (seen[k]) continue;
        const double new_dist =
                    dist[j] + cost[i][k] - u[i] - v[k];
        if (dist[k] > new_dist) {
          dist[k] = new_dist;
          dad[k] = j;
        }
      }
    }
    // update dual variables
    for (int k = 0; k < n; k++) {
      if (k == j || !seen[k]) continue;
      i = Rmate[k];
      v[k] += dist[k] - dist[j];
      u[i] -= dist[k] - dist[j];
    }
    u[s] += dist[j];
    // augment along path
    while (dad[j] >= 0) {
      const int d = dad[j];
      Rmate[j] = Rmate[d];
      Lmate[Rmate[j]] = j;
      j = d;
    }
    Rmate[j] = s;
    Lmate[s] = j;
    
    mated++;
  }
  
  double value = 0;
  for (i = 0; i < n; i++)
    value += cost[i][Lmate[i]];
  
  return value;
}

int main(void){
  int i, j;
  int k;
  ii p1[LIM], p2[LIM];
  while(scanf("%d%d", &n, &r)==2){
    FOR(i, 0, n){
      scanf("%d%d", &p1[i].X, &p1[i].Y);
    }
    FOR(i, 0, r){
      scanf("%d%d", &p2[i].X, &p2[i].Y);
    }
    FOR(i, 0, n){
      FOR(j, 0, r){
	k=abs(p2[j].X-p1[i].X)+abs(p2[j].Y-p1[i].Y);
	cost[i][j]=k;
      }
      FOR(j, r, n) cost[i][j]=INF;
    }
    /*printf("matriz cost[][]\n");
    FOR(i, 0, n){
      printf("fila %d:", i);
      FOR(j, 0, r){
	printf(" %.0lf", cost[i][j]);
      }
      puts("");
      }*/
    printf("%d\n", int(MinCostMatching())%INF);
  }
  return 0;
}