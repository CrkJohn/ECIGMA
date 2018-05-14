from sys import stdin
from sys import setrecursionlimit

def foundBCC(lo): # st[lo:] es un bcc
    global bccCnt, st,bcc
    if len(st)==0: return
    for i in range(lo,len(st)):
        u,v = st[i]
        bcc[(u,v)] = bcc[(v,u)] = bccCnt
    bccCnt+=1
    st = st[:lo]
    return


def articulationPoint(u):
    global num,low, dfsCounter, p ,a ,g , counterChild, dfsParent,bridge, bccCnt, st,bcc
    num[u] = low[u] = dfsCounter
    dfsCounter+=1
    for v in g[u]:
        if(num[v]==-1):
            st.append((u,v))
            p[v] = u
            if(dfsParent == u):
                counterChild+=1
            articulationPoint(v)
            if(low[v]>=num[u]):
                a[u] = True
                if(low[v]>num[u]):
                    bridge.append([min(u,v),max(u,v)])
                 ##Biconected Component
                for lo in range(len(st)-1, -1, -1):
                    if st[lo]==(u,v):
                        foundBCC(lo)
                        break        
            low[u] = min(low[u],low[v])
        elif( v != p[u]):
            low[u] = min(low[u],num[v])
    
def main():
    global num,low, dfsCounter, p,a,g, counterChild, dfsParent,bridge, bccCnt, st,bcc
    n,e  = [int(x) for x in stdin.readline().strip().split()]
    num = [ -1 for x in range(n+1)]
    low = [ -1 for x in range(n+1)]
    p = [ x for x in range(n+1)]
    a = [ False for x in range(n+1)]
    st = list()
    bridge  = list()
    bcc = {}
    g = [[] for i in range(n+1)]
    for G in range(e):
        u,v = [int(x) for x in stdin.readline().strip().split()]
        g[u].append(v)
        g[v].append(u)
    dfsCounter  = 0
    bccCnt =  0
    
    for i  in range(n):
        if(num[i]==-1):
            dfsParent = i
            counterChild = 0
            num[i] = low[i] = dfsCounter
            articulationPoint(i)
            foundBCC(0)
            a[i] = counterChild>1


    print("Puntos de articulacion")
    for  i in range(n):
       if(a[i]):
           print(i)
    print("Puentes")
    for  i in bridge:
        print(*i)
    print("Biconectados")
    for u in bcc:
        print(u,bcc[u])
        
main()
