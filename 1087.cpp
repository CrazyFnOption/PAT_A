/*
    还是传统方法的一道题目，dijkstra 加上 dfs 基本做法，注意变量之间的关系

    这道题 还是因为自己变量弄错了 比较的时候写错了 所以耗时有点久 

    或者这道题直接使用 dfs  然后把相关要计算的变量全部变成 局部变量

    下面这种方法就是变成局部变量的方法了
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

const int inf = 0x3f3f3f3f;

int n, k;
string s,beg;
map<string,int> m;
string ms[205];
int hap[205];
int cost[205][205];
vector<int> pre[205];
int dis[205];
bool vis[205];
int cnt,_end,tmpcnt;
double Maxavi = -1,avi;
int sum,tmpsum,Maxsum = -1;
int dd ,tmpdd = 0;
vector<int>res,tmpres;

void dijkstra(int beg) {
    memset(dis,inf,sizeof dis);
    dis[beg] = 0;
    for (int i = 0; i < n; i++) {
        int Min = inf,index = -1;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && dis[j] < Min) {
                Min = dis[j];
                index = j;
            }
        }
        if (index == -1) return;
        vis[index] = true;
        for (int u = 0; u < n; u ++) {
            if (!vis[u] && cost[index][u] != inf) {
                if (dis[u] > dis[index] + cost[index][u]) {
                    pre[u].clear();
                    pre[u].push_back(index);
                    dis[u] = dis[index] + cost[index][u];
                }
                else if (dis[u] == dis[index] + cost[index][u]) 
                        pre[u].push_back(index);
            }
        }
    }
}

void dfs(int x,int y) {
    //注意注意 这个一定要放在前面 要不然后面计算总和的时候不能算进去了。
    
    if (x == 0) {
        cnt++;
        
        double tmpavi = (double)y / (tmpres.size() - 1);
        if (Maxsum < y) {
            Maxsum = y;
            res = tmpres;
            Maxavi = tmpavi;
        }
        else if (Maxsum == y && Maxavi < tmpavi) {
            avi = Maxavi = tmpavi;
            res = tmpres;
        }

        return;
    }
    
    
    for (int i = 0; i < pre[x].size(); i++) {
        
        tmpres.push_back(pre[x][i]);
        dfs(pre[x][i], y + hap[pre[x][i]]);
        tmpres.pop_back();
    }
    
    
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> beg;
    ms[0] = beg;
    m[beg] = 0;
    memset(cost,inf,sizeof cost);
    for (int i = 1; i < n; i++) {
        cin >> s;
        m[s] = i;
        cin >> hap[i];
        ms[i] = s;
    }
    
    string a,b;
    int x;
    for (int i = 0; i < k; i ++) {
        cin >> a >> b >> x;
        cost[m[a]][m[b]] = cost[m[b]][m[a]] = x;
    }
    tmpcnt = 0;
    _end = m["ROM"];
    dijkstra(0);
    
    tmpres.push_back(_end);
    dfs(_end,hap[_end]);
    cout << cnt << " " << dis[_end] << " " << Maxsum << " " <<(int)Maxavi << endl;
    for (auto it = res.rbegin() ; it != res.rend() - 1; it++) {
        cout << ms[*it] << "->";
    }
    cout << "ROM";
    return 0;
}