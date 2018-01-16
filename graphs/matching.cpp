typedef pair<int,int>    ii;
typedef long long        ll;
typedef vector<int>      vi;

int v, match[LIM];
bool vis[LIM];
vi AL[LIM];

int Augment(int x){
  int j, r;
  if (vis[x]) return 0;
  vis[x]=true;
  FOR(j, 0, (int)AL[x].size()){
    r=AL[x][j];
    if (match[r]==-1 || Augment(match[r])){
      match[r]=x;
      return 1;
    }
  }
  return 0;
}

//inside int main(void)
  a=0;
  SET(match, -1);
  FOR(i, 0, v){
    SET(vis, 0);
    a+=Augment(i);
  }
  printf("%d\n", a);