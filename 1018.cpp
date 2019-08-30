/*
	首先 对于以前看到这样的一道题目，完全不会理解是什么意思，但是现在最起码想到了 dijkstra 算法来计算
    只不过在记录路径和比较路径的时候出了点问题

    其实这以前都接触过，但是没有形成有效连线，但是最起码现在知道了，应该是使用一个pre存取前驱，然后用dfs遍历，找条数的过程中依次比较。

*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <cmath>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 500 + 10;
int cap, n, _index, edge;
int num[maxn];
int dis[maxn][maxn];
int path[maxn];
bool vis[maxn];
vector<int> pre[maxn];

void dijkstra(int beg)
{
    memset(path, inf, sizeof path);
    memset(vis, false, sizeof vis);
    path[beg] = 0;

    for (int i = 0; i <= n; i++)
    {
        int Min = inf, ii = -1;
        for (int j = 0; j <= n; j++)
        {
            if (!vis[j] && path[j] < Min)
            {
                Min = path[j];
                ii = j;
            }
        }
        if (ii == -1)
            break;
        vis[ii] = true;
        for (int j = 0; j <= n; j++)
        {
            if (!vis[j] && dis[ii][j] != inf)
            {
                if ( path[ii] + dis[ii][j] < path[j])
                {
                    path[j] = path[ii] + dis[ii][j];
                    pre[j].clear();
                    pre[j].push_back(ii);
                }
                else if (path[ii] + dis[ii][j] == path[j]) {
                    pre[j].push_back(ii);
                }
            }
        }
    }
}

vector<int> route,tmp_route;
int minneed = inf,minback = inf;

void dfs(int u) {
    if (u == 0) {
        int need = 0,back = 0;
        for (int j = tmp_route.size() - 1; j >= 0; j--) {
            int i = tmp_route[j];
            //这个地方逻辑变换的时候出现了问题 不重要再次出错了
            if (num[i] > 0 || back > (-num[i])) back += num[i];
            else {
                need += -num[i] - back;
                back = 0;
            }
        }

        //真的，读题真的是pta甲级的通病，这里真的需要细心。加油。
        if (minneed > need || (minneed == need && minback > back)) {
            minneed = need;
            minback = back;
            route = tmp_route;
        }



        return;
    }
    tmp_route.push_back(u);
    for (int i = 0; i < pre[u].size();i++) {
        dfs(pre[u][i]);
    }
    //这里之所以要这样写的目的就在于，万一找不到路线了，那么说明这个前驱没有用，所以及时将其删除掉。
    tmp_route.pop_back();

}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    scanf("%d%d%d%d",&cap,&n,&_index,&edge);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&num[i]);
        num[i] -= cap / 2;
    }
    memset(dis, inf, sizeof dis);
    int a, b, c;
    for (int i = 0; i < edge; i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        dis[a][b] = c;
        dis[b][a] = c;
    }

    dijkstra(0);
    dfs(_index);
    
    printf("%d 0", minneed);
    for (int i = route.size() - 1; i >= 0; i--)
        printf("->%d", route[i]);
    printf(" %d", minback);

    return 0;
}