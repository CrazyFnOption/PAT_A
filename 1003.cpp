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
const int maxn = 505;
const int inf = 0x3f3f3f3f;
int n,m,_beg,_end;
int people[maxn];
bool vis[maxn];
int _map[maxn][maxn];
int dis[maxn];
int paths[maxn];
int Maxvalue[maxn];

void Dijkstra(int beg) {
    memset(dis,inf,sizeof dis);
    memset(vis,false,sizeof vis);
    dis[beg] = 0;
    paths[beg] = 1;
    Maxvalue[beg] = people[beg];
    
    for (int i = 0; i < n; i++) {
        int Min = 0x3f3f3f3f, index = -1;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && dis[j] < Min) {
                Min = dis[j];
                index = j;
            }
        }
        if (index == -1) break;
        vis[index] = true;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && _map[index][j] != inf) {
                if (dis[index] + _map[index][j] < dis[j]) {
                    dis[j] = dis[index] + _map[index][j];
                    paths[j] = paths[index];
                    Maxvalue[j] = Maxvalue[index] + people[j];
                }
                else if (dis[index] + _map[index][j] == dis[j]) {
                    paths[j] += paths[index];
                    Maxvalue[j] = max(Maxvalue[j],Maxvalue[index] + people[j]);
                }
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n >> m >> _beg >> _end;
    for (int i = 0 ; i < n; i++) {
        cin >> people[i];
    }
    int x,y,val;
    memset(_map,inf,sizeof _map);
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> val;
        _map[x][y] = val;
        _map[y][x] = val;
    }

    Dijkstra(_beg);
    cout << paths[_end] << " " << Maxvalue[_end] << endl;


    return 0;
}