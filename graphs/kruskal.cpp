typedef vector<ii> 		vii;
typedef pair<double,ii> dii;
typedef vector<dii>		vdii;

vector<int> pset(1000), tam(1000);
int numberOfSets;
void initSet(int _size) {
	int i;
	pset.resize(_size); 
	tam.resize(_size);
	numberOfSets=_size;
	FOR(i, 0, _size) {
		pset[i] = i;
		tam[i] = 1;
	}
}
int findSet(int i) {
	return (pset[i]==i)? i :(pset[i] = findSet(pset[i]));
}
void unionSet(int i, int j) {
	int x, y;
	x = findSet(i);
	y = findSet(j);
	if (x==y) return;
	pset[x] = y;
	tam[y] += tam[x];
	numberOfSets--;
}
bool isSameSet(int i, int j) {
	return findSet(i) == findSet(j);
}
int sizeOfSet(int x){
	return tam[x] = tam[findSet(x)];
}

vdii vec;
vdii::iterator it;
double x[LIM], y[LIM];

//inside int main(void)
  initSet(n);
  vec.clear();
  FOR(i, 0, n){    //generating edge list
    FOR(j, i+1, n){
      vec.pb(mp(sqrt((x[i]-x[j])*(x[i]-x[j])+
                (y[i]-y[j])*(y[i]-y[j])), mp(i, j)));
    }
  }
  sort(vec.begin(), vec.end());
  suma=0.0;      //kruskal begins here
  for(it=vec.begin(); it!=vec.end(); it++){
    if (!isSameSet(it->second.first, it->second.second)){
      suma+=it->first;
      unionSet(it->second.first, it->second.second);
    }
  }
  printf("%.2lf\n", suma);
  
/*
SECOND BEST SPANNING TREE IN O(ELOGV)
INSTEAD OF O(EV)
STEPS:
1)Run Kruskal's Algorithm as normal, saving the edges as Adjacency List (AL) and saving the edges not included in the MST in another Adjacency List (OTHER)
2)Precalculate mat[i][j]='largest edge cost along the path i-j in AL (here done with spread() function)
3)For each edge (u-v) in OTHER, minimize: cost of MST - mat[u][v] + cost of (u-v) in OTHER
4)The minimum found in 3) is the cost of the second best ST
*/
typedef pair<int,ii> tri;

dii AL[LIM];
int t, lim, mat[LIM][LIM], curr;

int p[LIM], rk[LIM], nsets;
void dsinit(int _n){ nsets=_n; SET(p, -1); SET(rk, 0);}
int parent(int x){
  if (p[x]==-1) return x;
  else return p[x]=parent(p[x]);
}
bool dsunion(int x, int y){
  x=parent(x); y=parent(y);
  if (x!=y){
    if (rk[x]>rk[y]) swap(x, y);
    if (rk[x]==rk[y]) rk[y]+=1;
    p[x]=y; nsets--;
  }
  return (x!=y);
}

void spread(int u){
  int i, v, w;
  loop(i, 0, (int)AL[u].size()){
    v=AL[u][i].x;
    w=AL[u][i].y;
    if (mat[curr][v]>=0) continue;
    mat[curr][v]=max(mat[curr][u], w);
    spread(v);
  }
}

int main(void){
  int i, n, m, ncasos, caso=0, nstates, j, a;
  int roads;
  //READ("ACMContestAndBlackout10600.txt");
  scanf("%d", &ncasos);
  loop(caso, 0, ncasos){
    scanf("%d%d", &n, &m);
    roads=0;
    loop(i, 0, m){
      scanf("%d %d %d", &edge[i].y.x, &edge[i].y.y, &edge[i].x);
      edge[i].y.y-=1; edge[i].y.x-=1;
    }
    loop(i, 0, n) AL[i].clear();
    dsinit(n);
    t=a=roads=0;
    //normal Kruskal's for MST
    sort(edge, edge+m);
    while (t<m){
      if (dsunion(edge[t].y.x, edge[t].y.y)){
        roads+=edge[t].x;
        AL[edge[t].y.x].pb(ii(edge[t].y.y, edge[t].x));
        AL[edge[t].y.y].pb(ii(edge[t].y.x, edge[t].x));
      }else if (edge[t].y.x != edge[t].y.y){
        other[a++]=edge[t];
        //printf("-->%d %d,%d\n", other[a-1].x, other[a-1].y.x, other[a-1].y.y);
      }
      t++;
    }
    //precalculating mat[i][j];
    loop(curr, 0, n){
      SET(mat[curr], -1);
      spread(curr);
    }
    //here saving the second best ST
    t=0x3FFFFFFF;
    loop(i, 0, a){
      t=min(t, (roads - mat[other[i].y.x][other[i].y.y] + other[i].x));
    }
    printf("%d %d\n", roads, t);
  }
  return 0;
}
