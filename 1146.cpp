/*
	拓扑排序的知识 要掌握清楚 入度为0的点需要去关注一下，然后再依次筛选接下来的点
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

const int maxn = 1005;
vector<int>v[maxn];
vector<int>ori,tmp;
vector<int>res;


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,k,x;
    cin >> n >> m;
    ori.resize(n + 5);
    tmp.resize(n + 5);
    int a,b;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        ori[b]++;
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        tmp.clear();
        tmp = ori;
        bool flag = true;
        for (int u = 0; u < n; u++) {
            cin >> x;
            if (tmp[x]) flag =false;
            for (int j = 0; j < v[x].size(); j++) {
                tmp[v[x][j]]--;
            }
        }
        if (!flag) res.push_back(i);
    }
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i != res.size() - 1) cout << " ";
    }
    return 0;
}