from sys import stdin
from heapq import * 

def dijkstra(src):
    ans = [ float('inf') for i in range(len(graph)) ] ;
    ans[source] = 0
    visited = [ False for i in range(len(graph)) ]
    prev = [ -1 for i in range(len(graph)) ]
    pq = [ (0,src) ]
    while len(pq)!=0:
        wu,u = hpp(pq)
        if not(visited[u]):
          # assert ans[u]==wu
          for v,wv in g[u]:
            if wu+wv < ans[v]:
              ans[v] = wu+wv
              prev[v] = u
              heappush(pq,(ans[v],v))
          visited[u] = True
  return ans,prev
    
def main():
    global g
    n,e  = [int(x) for x in stdin.readline().strip().split()]
    g = [[] for i in range(n+1)]
    for G in range(e):
        u,v,w = [int(x) for x in stdin.readline().strip().split()]
        g[u].append(v)
        g[v].append(u)
 
main()
