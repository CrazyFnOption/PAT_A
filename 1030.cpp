/*
	前面做过类似的题，所以很快就能够自己做出来了

    就是一个最短路求法，然后再最短路中表明前面一个节点

    然后使用dfs回溯的过程中去寻找相应的条件，属于一道简单的题目。
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
#include<stack>

using namespace std;

int n,m,s,d;
const int maxn = 500 + 10;
const int inf = 0x3f3f3f3f;
int dis[maxn][maxn];
int tdis[maxn];
bool vis[maxn];
int cost[maxn][maxn];

vector<int>pre[maxn];
stack<int>path,res;
int dis_sum = 0,cost_sum = 0;
int res_sum;

void dijkstra(int beg) {
    memset(vis,false,sizeof false);
    memset(tdis,inf,sizeof tdis);
    tdis[beg] = 0;
    int index,Min;
    for (int i = 0; i < n; i++) {
        index = -1;
        Min = inf;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && Min > tdis[j]) {
                Min = tdis[j];
                index = j;
            }
        }

        if (index == -1) return;
        vis[index] = true;
        for (int j = 0; j < n; j++) {
            if(!vis[j] && dis[index][j] != inf) {
                if (tdis[j] > tdis[index] + dis[index][j]) {
                    tdis[j] = tdis[index] + dis[index][j];
                    pre[j].clear();
                    pre[j].push_back(index);
                }
                else if (tdis[j] == tdis[index] + dis[index][j]) {
                    pre[j].push_back(index);
                }
            }
        }

    }
    return;
}
int Min = inf;
void dfs(int x) {
    if (x == s) {
        if (Min > cost_sum) {
            Min = cost_sum;
            res = path;
            res_sum = dis_sum;
        }
        cost_sum = 0;
        dis_sum = 0;
        return;
    }
    path.push(x);
    for (int i = 0; i < pre[x].size(); i++) {
        cost_sum += cost[x][pre[x][i]];
        dis_sum += dis[x][pre[x][i]];
        dfs(pre[x][i]);
    }
    path.pop();
    cost_sum = 0;
    dis_sum = 0;
    return;
}


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    scanf("%d%d%d%d",&n,&m,&s,&d);
    int a,b,t,tt;

    memset(dis,inf,sizeof dis);
    memset(cost,inf,sizeof cost);

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d %d",&a,&b,&t,&tt);
        dis[a][b] = dis[b][a] = t;
        cost[a][b] = cost[b][a] = tt;
    }
    dijkstra(s);
    dfs(d);
    res.push(s);
    while (!res.empty()) {
        printf("%d ",res.top());
        res.pop();
    }
    printf("%d %d",res_sum,Min);
    return 0;
}