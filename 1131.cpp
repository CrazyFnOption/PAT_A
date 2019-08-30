/*
	使用了bfs去求解这道题，让人觉得困难的地方是不知道该怎么解决地铁线路的问题
    就主要是线路之间的链接，让我真的很无语，不知道这个样子该怎么去描写。

    看懂这道题的记录方法了，就是只能一站一站的去记录，之前觉得会超时，不过现在觉得还好

    这里只记录两站之间的关系，并且将两站进行一个有效的相加，记录一个值 就当是使用哈希的办法，得到属于几号线内

    这道题还需要还需要去花时间学习一下 spfa的做法
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>


using namespace std;

#define INT_MAX 0x3f3f3f3f
map<int, int> line;                //存储一条边所属线路
vector<int> graph[10005], past[10005], path; //图、最短路径中每个结点的先驱结点、临时的最短路径
//存储最终换乘站最少的最短路径，注意trans中只存储首尾结点和换乘站，first成员代表换乘站编号，second成员代表到达first成员的线路编号
vector<pair<int, int> > trans;
int n, m, k, start, dest, dis[10005]; //dis表示到达每个结点时的最短路径长度

void DFS(int v)
{                      //深度优先遍历所有最短路径找出其中换乘站最少的路径
    path.push_back(v); //结点编号压入最短路径中，注意遍历到起点时，整个路径是倒序存储在path中的
    if (v == start)
    {                                                                                       //到达起点
        vector<pair<int, int> > tempTrans = {{start, -1}};                                   //当前最短路径所包含的换乘站
        for (int i = path.size() - 2; i > 0; --i)                                           //倒序遍历整个path
            if (line[path[i - 1] * 10000 + path[i]] != line[path[i] * 10000 + path[i + 1]]) //当前结点是换乘站
                tempTrans.push_back({path[i], line[path[i] * 10000 + path[i + 1]]});
        tempTrans.push_back({dest, line[path[1] * 10000 + dest]}); //将终点放入tempTrans中
        if (trans.empty() || tempTrans.size() < trans.size())      //trans为空或tempTrans为换乘站更少的最短路径
            trans = tempTrans;                                     //更新trans
    }
    for (int i : past[v]) //遍历所有先驱结点
        DFS(i);           //深度优先遍历先驱结点
    path.pop_back();      //将当前结点弹出
}

//相当于加上堆优化的dijkstra算法
void BFS()
{ //求解所有最短路径
    for (int i = 0; i < 10005; ++i)
    { //初始化past和dis
        past[i].clear();
        dis[i] = INT_MAX;
    }
    queue<int> q;   //队列
    dis[start] = 0; //起点的dis初始化为0
    q.push(start);  //起点入队
    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        if (dis[p] > dis[dest]) //当前结点的dis大于终点的dis，该结点一定不是最短路径中的结点
            continue;
        for (int i : graph[p])
        { //遍历结点p能到达的所有结点
            if (dis[i] >= dis[p] + 1)
            {                          //到达结点的dis可更新
                if (dis[i] == INT_MAX) //结点i没有入队过
                    q.push(i);         //结点i入队
                dis[i] = dis[p] + 1;   //更新结点i的dis
                if (dis[i] > dis[p] + 1)
                    past[i].clear();
                past[i].push_back(p); //更新结点i的past
            }
        }
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &m, &start);
        for (int j = 1; j < m; ++j, start = dest)
        {
            scanf("%d", &dest);
            line.insert({start * 10000 + dest, i});
            line.insert({dest * 10000 + start, i});
            graph[start].push_back(dest);
            graph[dest].push_back(start);
        }
    }

    scanf("%d", &k);

    while (k--)
    {
        scanf("%d%d", &start, &dest);
        BFS();
        path.clear();
        trans.clear();
        DFS(dest);
        printf("%d\n", dis[dest]);
        for (int i = 1; i < trans.size(); ++i)
            printf("Take Line#%d from %04d to %04d.\n", trans[i].second, trans[i - 1].first, trans[i].first);
    }
    return 0;
}