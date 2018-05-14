from sys import stdin
def bellman(src):
    dist = [float("inf")]*V
    dist[src]  = 0
    for i in range(1,V):
        for edge in Edges:
            u,v,w = edge
            if dist[v] > dist[u]+w:
                dist[v] = dist[u]+w
    for edge in Edges:
        u,v,w = edge
        if dist[v] > dist[u]+w:
            return True
    return False
def main():
    casos = int(stdin.readline().strip())
    global Edges,V
   
    for i in range(casos):
        Edges=list()
        V,E=[int(x) for x in stdin.readline().strip().split()]
        for i in range(E):
            u,v,w = [int(x) for x in stdin.readline().strip().split()]
            Edges.append((u,v,w))
        print("possible") if bellman(0) else print("not possible")
main()
