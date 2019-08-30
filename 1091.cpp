/*
    三个维度的bfs 其实到最后也是一道简单题 
    将每次遍历的点 计算一个值，计算相应的联通块  可能不能用dfs  因为会爆内存
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <string>
#include <queue>

using namespace std;
struct Node
{
    int x, y, z;
    Node(int xx, int yy, int zz) : x(xx), y(yy), z(zz) {}
};
int m, n, l, t, ans = 0, direct[6][3] = {
                             //6个方向
                             {-1, 0, 0},
                             {0, 1, 0},
                             {1, 0, 0},
                             {0, -1, 0},
                             {0, 0, 1},
                             {0, 0, -1},
};
bool graph[1300][130][80];
int BFS(Node p)
{
    int num = 0;
    queue<Node> q;
    q.push(p);
    graph[p.x][p.y][p.z] = false;
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        ++num;
        for (int i = 0; i < 6; ++i)
        {
            int x = p.x + direct[i][0], y = p.y + direct[i][1], z = p.z + direct[i][2];
            if (x >= 0 && x < m && y >= 0 && y < n && z >= 0 && z < l && graph[x][y][z])
            {
                q.push(Node(x, y, z));
                graph[x][y][z] = false;
            }
        }
    }
    return num;
}
int main()
{
    scanf("%d%d%d%d", &m, &n, &l, &t);
    for (int k = 0; k < l; ++k)
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                scanf("%d", &graph[i][j][k]);
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < l; ++k)
                if (graph[i][j][k])
                {
                    int temp = BFS(Node(i, j, k));
                    if (temp >= t)
                        ans += temp;
                }
    printf("%d", ans);
    return 0;
}