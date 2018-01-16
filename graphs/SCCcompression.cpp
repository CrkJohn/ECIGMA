int n, m, p[LIM], lo[LIM], num[LIM], dfscount, SCC;
int indeg[LIM];
bool vis[LIM];
di s, AL[LIM], AL2[LIM];
set<int> tm1[LIM];

void tarjan(int u){
	int v, j;
	lo[u]=num[u]= dfscount++;
	s.pb(u);
	vis[u]=true;
	loop(j, 0, (int)AL[u].size()){
		v=AL[u][j];
		if (num[v]==0) tarjan(v);
		if (vis[v]) lo[u]=min(lo[u], lo[v]);
	}
	if (lo[u]==num[u]){
		//printf("SCC=%d\n", SCC);
		do{
			v=s.back(); s.pop_back();
			//printf("%d\n", v+1);
			vis[v]=0;
			p[v]=SCC;
		}while (u!=v);
		SCC++;
	}
}

//Inside main
loop(i, 0, n) num[i]=lo[i]=0, vis[i]=false;
dfscount=1; SCC=0;
loop(i, 0, n){
	if (num[i]==0) tarjan(i);
}
loop(i, 0, n){
	loop(j, 0, (int)AL[i].size()){
		v=AL[i][j];
		if (p[i]!=p[v]) tm1[p[i]].insert(p[v]);
	}
}
loop(i, 0, n) indeg[i]=0;
loop(i, 0, SCC){
	for (set<int>::iterator it=tm1[i].begin(); it!=tm1[i].end(); it++){
		v=(*it);
		//printf("%d -> %d\n", i+1, v+1);
		AL2[i].pb(v); indeg[v]+=1;
	}
}