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
int n, l, k;

vector<int> v[1005];
bool vis[1005];

struct node {
    int val;
    int level;
    node(int a = 0, int b = 0) :val(a),level(b){}
};

int total;

void bfs(int x) {
    vis[x] = true;
    queue<node>q;
    q.push(node(x,0));
    while (!q.empty()) {
        node now = q.front();
        q.pop();
        int u = now.val;
        //这个地方return 和 continue 是一样的结果 说明题目数据很水
        //应该这里是 continue 才是正确的
        if (now.level == l) continue;

        // 不过后面相当 既然是bfs的话 ，那么当第一个到达相应层数的话，那么说明后面也同样都到达了，
        //因为是一个一个计算的嘛。

        //在30分里面算是一道简单题了
        for (int i = 0; i < v[u].size(); i++) {
            int t = v[u][i];
            if (!vis[t]) {
                total++;
                vis[t] = true;
                q.push(node(t,now.level + 1));
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> l;
    int x, y;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        for (int j = 0; j < x; j++)
        {
            cin >> y;
            v[y].push_back(i);
        }
    }

    cin >> k;
    for (int i = 0; i < k; i++)
    {
        memset(vis, false, sizeof vis);
        total = 0;
        cin >> x;
        vis[x] = true;
        bfs(x);
        cout << total << endl;
    }

    return 0;
}