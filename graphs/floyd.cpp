//saving the shortest path from i to j
loop(i, 0, n) loop(j, 0, n) prev[i][j]=i;

loop(k, 0, n) loop(i, 0, n) loop(j, 0, n){
  if (mat[i][j]>mat[i][k]+mat[k][j]){
    mat[i][j] = mat[i][k] + mat[k][j];
    prev[i][j]=prev[k][j];
  }
}

//to print path: void PrintPath
void PrintPath(int ori, int dest){
  if (ori!=dest)
    PrintPath(ori, prev[ori][dest]);
  printf(" %d", dest+1);
}