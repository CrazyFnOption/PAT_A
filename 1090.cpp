/*
	还是那个简单的dfs 需要做到的就是将在dfs中的全局变量一次一次的清理干净
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int maxdepth, maxnum;
vector<vector<int> > e;
int n, x;
double p, r;
void dfs(int depth, int u)
{
    if (depth == maxdepth)
        ++maxnum;
    if (depth > maxdepth)
    {
        //这里的dfs是用来计算相等的条数作用的。
        maxnum = 1;
        maxdepth = depth;
    }
    for (int v = 0; v < e[u].size(); ++v)
        dfs(depth + 1, e[u][v]);
}
int main()
{
    scanf("%d%lf%lf", &n, &p, &r);
    r /= 100;
    int root;
    e.resize(n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &x);
        if (x == -1)
            root = i;
        else
            e[x].push_back(i);
    }
    dfs(0, root);
    printf("%.2f %d", p * pow(1 + r, maxdepth), maxnum);
    return 0;
}