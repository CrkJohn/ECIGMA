int cont, in[LIM];
char car[25], res[25];
bool vis[25];
vector<int> adjList[LIM];
//in-degree toposort, backtracking to visit all possible
//topological orderings
bool toposort(int nodo, int n){
	int b, i;
	bool ans=false, t;
	res[n]=car[nodo];
	if (n==cont-1){
		putchar(res[0]);
		FOR(i, 1, cont) printf(" %c", res[i]);
		putchar('\n');
		return true;
	}
	vis[nodo]=true;
	b=adjList[nodo].size();
	FOR(i, 0, b){
		in[adjList[nodo][i]]-=1;	//take out edges
	}
	FOR(i, 0, cont){
		if (!vis[i] && in[i]==0){
			t=toposort(i, n+1);
			ans = ans || t;
		}
	}
	FOR(i, 0, b){
		in[adjList[nodo][i]]+=1;	//puts edges again
	}
	vis[nodo]=false;
	res[n]=0;	
	return ans;
}