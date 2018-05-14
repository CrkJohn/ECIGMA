from sys import stdin
from heapq import *

def dijkstra2(src):
    global g
    n = len(g)
    inf = int(1e5)
    dist = [inf]*n
    dist[src] = 0
    h = [(0,src)]
    while len(h):
        d, u = heappop(h)
        #if dist[u]!=d:
        #    continue
        for v,w in g[u]:
            print("{}-w:{}-{} ".format(u,w,v))
            if d+w < dist[v]:
                dist[v] = d+w
                heappush(h, (d+w, v))
    return dist

def main():
    global g
    n,e  = [int(x) for x in stdin.readline().strip().split()]
    g = [[] for i in range(n+1)]
    for G in range(e):
        u,v,w = [int(x) for x in stdin.readline().strip().split()]
        g[u].append((v,w))
        g[v].append((u,w))
    print(dijkstra2(0))
main()

