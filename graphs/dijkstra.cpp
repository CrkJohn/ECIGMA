priority_queue<pii, vector<pii>, greater<pii> > pq;
forn(i, n) dis[i]=INF;  dis[s]=0;
while (!pq.empty()) pq.pop();
pq.push(pii(0, s));
while (!pq.empty()){
  pii par=pq.top(); pq.pop();
  int d=par.fi , u=par.se;
  if (d>dis[u]) continue;
  forn(j,len(adjList[u])){
    pii v=adjList[u][j];
    if (dis[u]+v.se < dis[v.fi]){
      dis[v.fi]= dis[u] + v.se;
      pq.push(pii(dis[v.fi],v.se));
    }
  }
}
