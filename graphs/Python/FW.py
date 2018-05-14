from sys import stdin
from heapq import *

def FW():
    for k in range(n):
        for i in range(n):
            for j in range(n):
                 g[i][j] = min(g[i][j],(g[i][k]+g[k][j]));

def main():
    global g,Edges
    n,e  = [int(x) for x in stdin.readline().strip().split()]
    g = [ [ 0 for i in range(n+1)] for j in range(n)]
    d = [ [ float('inf') for i in range(n+1)] for j in range(n)]
    Edges = list()
    for G in range(e):
        u,v,w = [int(x) for x in stdin.readline().strip().split()]
        g[u][v] = w
        g[v][u] = w
    print(FW())
main()

