di AL[LIM];
int AM[LIM][LIM], p[LIM];
void addEdge(int a, int b, int c) {
  AL[a].pb(b); AM[a][b] = c;
}
int maxFlowDinic(int s, int t) {
  int flow = 0, f, i, u, v;
  di q, nxt;
  while (true) {
    q.clear(); q.pb(s);
    SET(p, -1); p[s] = -2;
    nxt.clear();

		while(!q.empty()){
			u=q.front(); q.pop_front();
			if (u==t) break;
			loop(i, 0, (int)AL[u].size()){
				v=AL[u][i];
				if (v==t && AM[u][v]) nxt.pb(u);
				if (p[v]==-1 && AM[u][v]){
					p[v]=u; q.pb(v);
				}
			}
		}
    if (p[t] == -1) return flow;

    loop(i, 0, (int)nxt.size()){
    	v=t; u=nxt[i];
    	if (AM[u][v] && p[u]>=0){
				f=INF;
				do{
					f=min(f, AM[u][v]); v=u; u=p[v];
				}while(u>=0);
				if (f==0) continue;
				v=t; u=nxt[i];
				do{
					AM[u][v]-=f; AM[v][u]+=f;
					v=u; u=p[v];
				}while(u>=0);
				flow+=f;
    	}
    }
  }
  return flow;
}