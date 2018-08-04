#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<ctime>
using namespace std;
typedef long long ll;
#define maxn 222222
struct node
{
    int u,v,w,id;
    bool operator<(const node&b)const
    {
        return w<b.w;
    }
}edge[maxn];
int T,n,m,fa[maxn],W[maxn];
int vis[maxn],deep[maxn],p[maxn][21],Max[maxn][21];
typedef pair<int,int>P;
vector<P>G[maxn];
ll ans[maxn];
void add(int u,int v,int id)
{
    G[u].push_back(P(v,id)),G[v].push_back(P(u,id));
}
int find(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
ll kruskal(int n,int m)
{
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=n;i++)G[i].clear();
    int cnt=0;
    ll ans=0;
    sort(edge+1,edge+m+1);
    for(int k=1;k<=m;k++)
    {
        int u=edge[k].u,v=edge[k].v,w=edge[k].w,id=edge[k].id;
        int x=find(u),y=find(v);
        if(x!=y)
        {
            cnt++;
            fa[x]=y;
            ans+=w;
            add(u,v,id);
            vis[id]=1;
            if(cnt==n-1)return ans;
        }
    }
    return -1;
}
void dfs(int u,int f,int w)
{
    deep[u]=deep[f]+1,p[u][0]=f,Max[u][0]=w;
    for(int i=1;i<=20;i++)
    {
        if(deep[u]-(1<<i)<=0)break;
        int v=p[u][i-1];
        p[u][i]=p[v][i-1];
        if(W[Max[u][i-1]]<W[Max[v][i-1]])Max[u][i]=Max[v][i-1];
        else Max[u][i]=Max[u][i-1];
    }
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i].first,w=G[u][i].second;
        if(v!=f)dfs(v,u,w);
    }
}
int get_max(int x,int y)
{
    if(deep[x]<deep[y])swap(x,y);
    int temp=0,ans=0;
    for(int i=20;i>=0;i--)
        if(deep[x]-(1<<i)>=deep[y])
        {
            if(W[Max[x][i]]>temp)ans=Max[x][i],temp=W[ans];
            x=p[x][i];
        }
    if(x==y)return ans;
    for(int i=20;i>=0;i--)
        if(deep[x]-(1<<i)>0&&p[x][i]!=p[y][i])
        {
            if(W[Max[x][i]]>temp)ans=Max[x][i],temp=W[ans];
            if(W[Max[y][i]]>temp)ans=Max[y][i],temp=W[ans];
            x=p[x][i],y=p[y][i];
            if(x==y)break;
        }
    if(W[Max[x][0]]>temp)ans=Max[x][0],temp=W[ans];
    if(W[Max[y][0]]>temp)ans=Max[y][0],temp=W[ans];
    return ans;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
        W[i]=edge[i].w,edge[i].id=i;
    }
    memset(vis,0,sizeof(vis));
    ll sum=kruskal(n,m);
    deep[0]=0;
    dfs(1,0,0);
    for(int i=1;i<=m;i++)
    {
        int id=edge[i].id,u=edge[i].u,v=edge[i].v,w=edge[i].w;
        if(vis[id])ans[id]=sum;
        else
        {
            int t=get_max(u,v);
            ans[id]=sum+w-W[t];
        }
    }
    for(int i=1;i<=m;i++)printf("%I64d\n",ans[i]);          
    return 0;
}
