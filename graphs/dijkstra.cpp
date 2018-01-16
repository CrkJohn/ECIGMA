priority_queue<ii, vector<ii>, greater<ii> > pq;
loop(i, 0, n) dis[i]=INF;  dis[s]=0;
while (!pq.empty()) pq.pop();
pq.push(ii(0, s));
while (!pq.empty()){
  par=pq.top(); pq.pop();
  d=par.X; u=par.Y;
  if (d>dis[u]) continue;
  loop(j, 0, (int) adjList[u].size()){
    ii v=adjList[u][j];
    if (dis[u]+v.Y < dis[v.X]){
      dis[v.X]= dis[u] + v.Y;
      pq.push(ii(dis[v.X], v.X));
    }
  }
}