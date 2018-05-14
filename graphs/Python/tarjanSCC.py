from sys import stdin

def tarjan(u):
    global num,lo, dfsCounter, p,g,  st, vis, SCC
    lo[u]=num[u]= dfsCounter
    dfsCounter+=1
    st.append(u)
    vis[u]=1
    for j in range(len(g[u])):
        v=g[u][j]
        if (num[v]==-1):
            tarjan(v)
        if (vis[v]):
            lo[u]=min(lo[u], lo[v])
    if (lo[u]==num[u]):
        while(1):            
            v=st.pop()
            vis[v]=0
            p[v]=SCC
            if(u==v):break;
        SCC+=1

def main():
    global num,lo, dfsCounter, p,g,  st , vis , SCC
    n,e  = [int(x) for x in stdin.readline().strip().split()]
    num = [ -1 for x in range(n+1)]
    lo =  [ -1 for x in range(n+1)]
    p =   [ -1 for x in range(n+1)]
    vis = [ 0 for x in range(n+1)]
    st = list()
    g = [[] for i in range(n+1)]
    for G in range(e):
        u,v = [int(x) for x in stdin.readline().strip().split()]
        g[u].append(v)
        #g[v].append(u)
    dfsCounter  = 0
    SCC  = 0
    for i  in range(n+1):
        if(num[i]==-1):
            num[i] = lo[i] = dfsCounter
            tarjan(i)
    for i in range(1,n+1):
        print(i,p[i])
            
main()
