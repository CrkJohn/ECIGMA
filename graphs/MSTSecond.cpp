#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>

// https://www.topcoder.com/community/data-science/data-science-tutorials/range-minimum-query-and-lowest-common-ancestor/#Lowest%20Common%20Ancestor%20(LCA)
// https://blog.csdn.net/beihai2013/article/details/50402108
using namespace std;
typedef pair<int,int> pii;
const int MAXN = 200000 + 5;
int fa[MAXN][25], dep[MAXN], MaxEdge[MAXN][20];
int pa[MAXN];
vector<pii>lin[MAXN];
struct E
{
    int u, v, w;
    int num, vis;
}e[MAXN];
bool cmp(E a, E b){return a.w < b.w;}
bool cmp2(E a, E b){return a.num < b.num;}
int n, m;
int find_pa(int u){return u == pa[u] ? u : pa[u] = find_pa(pa[u]);}
void combine(int u, int v){pa[find_pa(u)] = pa[find_pa(v)];}
void dfs(int u, int p)
{
    dep[u] = dep[p] + 1;
    for(int i = 0 ; i < (int)lin[u].size() ; i++){
        int v = lin[u][i].first;
        if(v == p)  continue;
        dfs(v, u);
        fa[v][0] = u;
        MaxEdge[v][0] = lin[u][i].second;
    }
}
void LCA_init()
{
    for(int i = 1 ; (1 << i) < n ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(fa[j][i - 1] == -1)  continue;
            fa[j][i] = fa[fa[j][i - 1]][i - 1];
            MaxEdge[j][i] = max(MaxEdge[j][i - 1], MaxEdge[fa[j][i - 1]][i - 1]);
        }
    }
}
int query(int u, int v)
{
    if(dep[u] < dep[v]) swap(u, v);
//    int l = dep[u] - dep[v];
    int ans = 0;
//    printf("u = %d, v = %d\n", u, v);
    int temp = u;
//    printf("fa[u][0] = %d, fa[u][1] = %d\n", fa[u][0], fa[u][1]);
    for(int j = 24 ; j >= 0 ; j--){
        if(fa[u][j] != -1 && dep[fa[u][j]] >= dep[v])   ans = max(ans, MaxEdge[u][j]), u = fa[u][j];
    }
//    printf("u = %d, v = %d\n", u, v);
//    printf("for u = 2 fa[u][0] = %d, fa[u][1] = %d, MaxEdge[u][0] = %d\n", fa[2][0], fa[2][1], MaxEdge[u][0]);
//    printf("for u = 3 fa[u][0] = %d, fa[u][1] = %d, MaxEdge[v][0] = %d\n", fa[3][0], fa[3][1], MaxEdge[v][0]);
    if(u == v)  return ans;
    for(int j = 24 ; j >= 0 ; j--){
        if(fa[u][j] != fa[v][j]){
            ans = max(ans, MaxEdge[u][j]);  u = fa[u][j];
            ans = max(ans, MaxEdge[v][j]);  v = fa[v][j];
        }
    }
    ans = max(ans, MaxEdge[u][0]);
    ans = max(ans, MaxEdge[v][0]);
    return ans;
}
int main()
{
    while(scanf("%d%d", &n, &m) != EOF){
        for(int i = 1 ; i <= n ; i++)   pa[i] = i, lin[i].clear();
        for(int i = 0 ; i < m ; i++)    scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w), e[i].num = i, e[i].vis = 0;
        sort(e, e + m, cmp);
        int num = 0;
        long long ans = 0;
//        printf("first\n");
        for(int i = 0 ; i < m ; i++){
            if(find_pa(e[i].u) == find_pa(e[i].v))  continue;
            combine(e[i].u, e[i].v);
            num++;
            lin[e[i].u].push_back(make_pair(e[i].v, e[i].w));
            lin[e[i].v].push_back(make_pair(e[i].u, e[i].w));
            e[i].vis = 1;
            ans += e[i].w;
//            if(num == n - 1)    break;
        }
        memset(fa, -1, sizeof(fa));
        dep[0] = 0;
//        printf("second\n");
        dfs(1, 0);
//        printf("third\n");
//        system("pause");
        LCA_init();
        sort(e, e + m, cmp2);
        for(int i = 0 ; i < m ; i++){
//            printf("e[i].vis = %d\n", e[i].vis);
//            if(e[i].vis)    printf("%I64d\n", ans);
//            else{
                printf("%I64d\n", ans - query(e[i].u, e[i].v) + e[i].w);
//            }
        }
    }
    return 0;
}
