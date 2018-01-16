list<int> ts;
//based on Felix Halim: CP3 online material
void TopoSort2(int u){
  int j, v;
  dfs_num[u]=1; //visited
  loop(j, 0, (int)AL[u].size()){
    v=AL[u][j];
    if(dfs_num[v] == 0)
      TopoSort2(v);
  }
  ts.pushf(u);
}

//inside main(void)
  list<int>::iterator it;
  ts.clear();
  SET(dfs_num, 0);
  loop(i, 0, n){
    if (dfs_num[i]==0)
      TopoSort(i);
  }
  for(it; it!=ts.end(); it++)
    printf(" %d", *it);
  putchar('\n');