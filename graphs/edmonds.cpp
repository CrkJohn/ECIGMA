di AL[LIM];
int AM[LIM][LIM], f, s, t;
map<int,int> p, dist;
bool vis[LIM];

void augment(int v, int minedge){
  if (v==s){
    f=minedge;
  } else if (p.count(v)){
    if (vis[v]){ f=0; return; }
    vis[v]=true;
    minedge=min(minedge, AM[p[v]][v]);
    augment(p[v], minedge);
    AM[p[v]][v] -= f;
    AM[v][p[v]] += f; //printf("->%d", v);
  }
}

int EdmondsKarp(){
  int maxflow=0, u, v, i;
  di q;
  do{
    q.clear(); dist.clear();
    q.pb(s); dist[s]=0;
    while (!q.empty()){
      u=q.front(); q.pop_front();
      if (u==t) break;
      loop(i, 0, (int)AL[u].size()){
      	v=AL[u][i];
        if (AM[u][v]>0 && !dist.count(v)){
          dist[v] = dist[u]+1;
          q.pb(v); p[v]=u;
        }
      }
    }
    SET(vis, false); f=0;
    augment(t, INF); //puts("");
    maxflow+=f; //printf("maxflow=%d f=%d\n", maxflow, f);
  }while (f>0);
  return maxflow;
}