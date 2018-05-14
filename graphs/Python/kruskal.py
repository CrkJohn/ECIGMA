def Kruskal(Exc):
    global padre,rank
    Arbol=0
    componentes  = nodos
    Segundo_C = []
    padre = [x for x in range(nodos+1)]
    rank = [0 for x in range(nodos+1)]
    for i in range(arcos):
        Grafo= Krusk[i]
        if Buscar(Grafo[0]) != Buscar(Grafo[1]):
            Arbol+=Grafo[2]
            Union(Grafo[0],Grafo[1])
   

def Buscar(x):
    if( padre[x]!=x):
            padre[x]= Buscar(padre[x])
    return  padre[x]
def Union( x, y):
    xRaiz =  Buscar(x)
    yRaiz =  Buscar(y)
    if(xRaiz == yRaiz):     return
    if  rank[xRaiz] <  rank[yRaiz]:
         padre[xRaiz] = yRaiz
    elif  rank[xRaiz] >  rank[yRaiz]:
         padre[yRaiz] = xRaiz
    else:
         padre[yRaiz] = xRaiz
         rank[xRaiz]+=1
main()
