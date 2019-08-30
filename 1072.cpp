/*
	算是一道中规中矩的难度的题目，应用了dijkstra算法

    没有别的新颖的地方了。

    不过需要记住 如果用0x3f来初始化double变量的话 则不会得到正无穷大。

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
#include <iomanip>

using namespace std;
int n,m,k,cmax;
const int maxn = 1020;
const int inf = 0x3f3f3f3f;
int _map[maxn][maxn];
bool vis[maxn];
int dis[maxn];

struct node {
    double avi;
    double val;
    int id;
    node (int a = 0,double b = 0,double c = 0):id(a),avi(b),val(c){}

    bool operator < (const node &n) const {
        if (val != n.val) return val > n.val;
        if (avi != n.avi) return avi < n.avi;
        return id < n.id;
    }
};

void dijkstra(int beg) {
    memset(vis,false,sizeof vis);
    memset(dis,0x3f3f3f3f,sizeof dis);
    dis[beg] = 0;
    int Min,_index;
    for (int i = 0; i < n + m; i++) {
        Min = inf;
        _index = -1;
        for (int j = 1; j <= n + m; j++) {
            if (!vis[j] && Min > dis[j]) {
                Min = dis[j];
                _index = j;
            }
        }
        
        if (_index == - 1) return ;
        vis[_index] = true;
        
        for (int j = 1; j <= n + m; j++) {
            if (!vis[j] && _map[_index][j] != inf) {

                if (dis[j] > dis[_index] + _map[_index][j]) {
                    dis[j] = dis[_index] + _map[_index][j];
                }
            }
        }
        
    }
}

int getnum(const string &a) {
    string s;
    if (a[0] == 'G') {
        s = a.substr(1);
        return stoi(s) + n;
    }
    else return stoi(a);
}


int main()
{
    scanf("%d %d %d %d",&n,&m,&k,&cmax);
    string a,b;
    int c;
    memset(_map,inf,sizeof _map);
    for (int i = 0;i < k; i++) {
        cin >> a >> b >> c;
        int x = getnum(a);
        int y = getnum(b);
        _map[x][y] = _map[y][x] = c;
    }
    vector<node> res;
    for (int i = 1; i <= m; i++) {
        dijkstra(i + n);
        double sum = 0;
        double Min = inf;
        bool flag = true;
        for (int u = 1; u <= n; u++) {
            if (dis[u] > cmax) {
                flag = false;
                break;
            }
            sum += dis[u];
            //cout << sum << endl;
            Min = min((double)dis[u],Min);
        }
        
        if (flag) {
            double avi = sum / n;
            res.push_back(node(i+n,avi,Min));
        }
    }

    if (res.empty()) {
        cout << "No Solution" << endl;
    }
    else {
        sort(res.begin(),res.end());
        int id = res[0].id;
        if (id > n) cout << "G" << id - n << endl;
        else cout << id << endl;
        cout << fixed << setprecision(1) << res[0].val << " " << res[0].avi;
    }

    return 0;
}