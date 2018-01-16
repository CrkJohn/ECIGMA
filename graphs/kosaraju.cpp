typedef vector<int>   vi;
int n;
vi AL1[LIM], AL2[LIM];
stack<int> s;
bool vis[LIM];

int Kosaraju(int u, int pass){
  int i, v;
  vi neighbor=(pass==1) ? AL1[u] : AL2[u];
  vis[u]=1;
  loop(i, 0, (int)neighbor.size()){
    v=neighbor[i];
    if (!vis[v]) Kosaraju(v, pass);
  }
  if (pass==1) s.push(u);
}

//inside int main(void)
SET(vis, 0);
while(!s.empty()) s.pop();
loop(i, 0, n){
  if (!vis[i]) Kosaraju(i, 1);
}
SET(vis, 0);
SCC=0;
while(!s.empty()){
  a=s.top(); s.pop();
  if (!vis[a]){
    SCC++;
    Kosaraju(a, 2);
  }
}
printf("%d\n", SCC);