
// ii v = (n,w) || (w,n)
//taken from: Competitive Programming 2

const int DFS_WHITE = -1;
 
void articulationPointAndBridge(int u) {
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
  for (int j = 0; j < (int)AdjList[u].size(); j++) {
    ii v = AdjList[u][j];
    if (dfs_num[v.first]==DFS_WHITE){ //tree edge
      dfs_parent[v.first] = u;
      if (u == dfsRoot) rootChildren++; // special case
      articulationPointAndBridge(v.first);
      if (dfs_low[v.first] >= dfs_num[u])
        articulation_vertex[u] = true;
      if (dfs_low[v.first] > dfs_num[u]) // for bridge
        printf("Edge (%d, %d) is a bridge\n", u, v.first);
      dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
      // updated dfs_low[u]
    }else if (v.first != dfs_parent[u])
      dfs_low[u] = min(dfs_low[u], dfs_num[v.first]);
  }
}

// inside int main()
  dfsNumberCounter = 0; dfs_num.assign(V, DFS_WHITE);
  dfs_low.assign(V, 0);
  dfs_parent.assign(V, 0);
  articulation_vertex.assign(V, 0);
  printf("Bridges:\n");
  for (int i = 0; i < V; i++)
    if (dfs_num[i] == DFS_WHITE) {
      dfsRoot = i; rootChildren = 0;
      articulationPointAndBridge(i);
      articulation_vertex[dfsRoot]=(rootChildren>1);
    }
  printf("Articulation Points:\n");
  for (int i = 0; i < V; i++)
    if (articulation_vertex[i])
      printf(" Vertex %d\n", i);