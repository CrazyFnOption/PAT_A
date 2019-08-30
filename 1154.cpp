#include <iostream>
#include <cstdio>
#include <unordered_set>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e4 + 10;
int col[maxn];
struct vertex
{ //创建一个结构体表示一条边的两个顶点
    int x, y;
} graph[maxn];
int main()
{
    //	freopen("1154.txt","r",stdin);
    int n, m, k, color;
    scanf("%d %d", &n, &m);
    fill(col, col + n, -1);
    for (int i = 0; i < m; i++)
        scanf("%d %d", &graph[i].x, &graph[i].y);
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        int flag = 0;
        unordered_set<int> st; //用unordered_set去重（不用排序）统计颜色种类（即容器size）
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &color);
            col[j] = color;
            st.insert(color);
        }
        for (int j = 0; j < m; j++)
        { //遍历m条边，开始写成n个顶点了，扣了2分
            if (col[graph[j].x] == col[graph[j].y])
            { //如果有不符合条件的将flag置1
                flag = 1;
                break;
            }
        }
        if (flag)
            printf("No\n");
        else
            printf("%d-coloring\n", st.size());
    }
    return 0;
}