/*
	仍然是一道特别简单的建造树的题目，需要使用的是bfs
    根据完全二叉树的性质就可以解决这道题 bfs按照顺序进行编号

    而dfs这是看看最大的编号是否与其相同，如果大于 才不是完全二叉树
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

int n;

struct Node
{
    int left;
    int right;
} node[25];

bool vis[25];
int last;

bool level(int x)
{
    queue<int> q;
    q.push(x);
    int cnt = 0;
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        cnt++;
        last = now;
        if (now == -1)
            return false;
        if (cnt == n)
        {
            last = now;
            return true;
        }
        int l = node[now].left;
        int r = node[now].right;
        q.push(l);
        q.push(r);
    }
    return true;
}

int main()
{
    cin >> n;
    string a,b;
    //问题出现在了这地方，不一定只有个位数，这里还会出现两位数，所以不能仅仅用一个字符表示
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        getchar();
        if (a == "-")
            node[i].left = -1;
        else
        {
            node[i].left = stoi(a);
            vis[node[i].left] = true;
        }

        if (b == "-")
            node[i].right = -1;
        else
        {
            node[i].right = stoi(b);
            vis[node[i].right] = true;
        }
    }

    int root;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            root = i;
            break;
        }
    }

    if (level(root))
        printf("YES %d\n", last);
    else
        printf("NO %d\n", root);

    return 0;
}