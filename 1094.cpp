/*
	这道题使用了两种方法  一个dfs  不过比平常dfs要多的就是  记录每一个点的状态

    这道题的体现就在于 其要记录每一层的节点个数，当前层数的节点个数

    这道题新颖就体现在了找到节点数最多的地方  输出层数和节点数

    dfs很好写 这里学习一下 bfs里对于这道题的写法

    类比一下 有的回收
*/
#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <queue>
#define MAX 101
using namespace std;
int graph[MAX][MAX];
int maxNum = INT_MIN, level;
void cengci(int cur)
{
    queue<int> que;
    int thisNum = 1;

    int tempThisNum = 0, tempLevel = 0;
    que.push(cur);
    while (!que.empty())
    {
        tempLevel++;
        for (int j = 0; j < thisNum; j++)
        {
            int x = que.front();
            que.pop();
            for (int i = 0; i < MAX; i++)
            {
                //这里实际上就是在找哪一层最多的人数了
                if (graph[x][i] == 1)
                {
                    que.push(i);
                    tempThisNum++;
                }
            }
        }
        thisNum = tempThisNum;

        if (maxNum < tempThisNum)
        {
            maxNum = tempThisNum;
            level = tempLevel;
        }
        tempThisNum = 0;
    }
}
int main()
{
    int numOfNode, numOfChild;
    scanf("%d%d", &numOfNode, &numOfChild);
    for (int i = 1; i <= numOfChild; i++)
    {
        int x, num;
        scanf("%d%d", &x, &num);
        for (int j = 0; j < num; j++)
        {
            int y;
            scanf("%d", &y);
            graph[x][y] = 1;
        }
    } ///输入完成

    ///层次遍历
    if (numOfNode > 1)
    {
        cengci(1);
        cout << maxNum << " " << level + 1;
    }
    else
        cout << 1 << " " << 1;
    return 0;
}