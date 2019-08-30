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

const int maxn = 1008;
int N,M,K;
bool dis[maxn][maxn];
bool vis[maxn];

void dfs(int x) {
    vis[x] = true;
    for (int i = 1; i <= N; i++) {
        if (vis[i] == false && dis[x][i] == true) {
            dfs(i);
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M >> K;
    int a,b;
    memset(dis,false,sizeof dis);
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        dis[a][b] = dis[b][a] = true;
    }

    int tmp;

    for (int i = 0; i < K; i++) {
        memset(vis,false,sizeof vis);
        cin >> tmp;
        vis[tmp] = true;
        int cnt = 0;
        for (int i = 1; i <= N; i++) {
            if (vis[i] == false) {
                dfs(i);
                cnt++;
            }
        }
        cout << cnt - 1 << endl;

    }  

    return 0;
}