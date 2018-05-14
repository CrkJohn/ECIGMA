from sys import stdin
#https://www.youtube.com/watch?v=RpgcYiky7uw
def kosaraju(u,passDfs,vu):
    global g,topo,gR
    vis[u] = 1
    adj =   g[u] if (passDfs == 1)  else  gR[u]
    for v in adj:
        if not vis[v]:
            kosaraju(v,passDfs,vu)
    if(passDfs==1):
        st.append(u)
    else:
        vu.append(u)


def main():
    global g , vis ,st,gR
    n,e  = [int(x) for x in stdin.readline().strip().split()]
    vis =[ False for x in range(n+1)]
    g = [[] for i in range(n+1)]
    gR = [[] for i in range(n+1)]
    
    st = list()
    for G in range(e):
        u,v = [int(x) for x in stdin.readline().strip().split()]
        g[u].append(v)
        gR[v].append(u)
    for i in range(n+1):
        if not(vis[i]):
            kosaraju(i,1,[])
    print(st)
    rev  = st[::-1]
    SCC = 0
    vis =[ False for x in range(n+1)]
    print(rev)
    compresionDelGrafo = list()
    for u in rev:
        if not(vis[u]):
            vu = list()
            kosaraju(u,2,vu)
            compresionDelGrafo.append(vu)
            SCC+=1
    print( *[(vu) for vu in compresionDelGrafo ])
  
main()




