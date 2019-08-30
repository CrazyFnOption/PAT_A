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

const int maxn = 205;
bool mmap[maxn][maxn];
bool vis[maxn];
bool dis[maxn];
int num[maxn];

vector<int>v[maxn];
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,k,x,t;
    cin >> n >> m;
    int a,b;
    for (int i = 0;i < m; i++) {
        cin >> a >> b;
        mmap[a][b] = mmap[b][a] = true;
        dis[a] = dis[b] = true;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cin >> k;
    while (k --) {
        memset(vis,false,sizeof vis);
        cin >> x;
        bool flag = false;
        
        for (int i = 0;i < x; i++) {
            cin >> num[i];
        }

        if (x == 1 && !dis[num[0]]) {
            cout << "Yes" << endl;
            continue;
        }

        for (int i = 0; i < x; i++) {
            vis[num[i]] = true;
            for (int j = i + 1; j < x; j++) {
                vis[num[j]] = true;
                if (!mmap[num[i]][num[j]]) {
                    cout << "Not a Clique" << endl;
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
        if (flag) continue;
        bool res = false;

        for (int i = 0; i < v[num[0]].size(); i++) {
            int u = v[num[0]][i];
            
            if (vis[u]) continue;
            int ans = 1;
            for (int j = 1; j < x; j++) {
                if (mmap[u][num[j]]) ans++;
            }
            if (ans == x ) {
                cout << "Not Maximal" << endl;
                res = true;
                break;
            }
        }
        if (!res) cout << "Yes" << endl;
    }
    return 0;
}