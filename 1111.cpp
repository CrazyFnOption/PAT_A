/*
	one-way单程的意思 这年头 英语不好题目压根就没办法做出来

    调试bug是一件很正常的事情，只有没有重大的错误，一般调试bug都算是一项简单的任务呢

    还算简单的一道题目吧 相当于是一发AC
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

int n,m;
int _beg,_end;

const int maxn = 505;
const int inf = 0x3f3f3f3f;

int mmap[maxn][maxn];
int tmap[maxn][maxn];
int ddis[maxn];
int tdis[maxn];
bool vis[maxn];
vector<int>mpre[maxn];
vector<int>tpre[maxn];
vector<int>mres,tempmres;
vector<int>tres,temptres;
int dans = 0,tans = 0;

void dijkstra1(int x) {
    memset(vis,false,sizeof vis);
    memset(ddis,0x3f3f3f3f,sizeof ddis);
    ddis[x] = 0;
    for (int i = 0; i < n; i++) {
        int Min = 0x3f3f3f3f,index = -1;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && ddis[j] < Min) {
                Min = ddis[j];
                index = j;
            }
        }
        if (index == -1) return;
        vis[index] = true;
        for (int u = 0; u < n; u++) {
            if (!vis[u] && mmap[index][u] != inf) {
                if (ddis[u] > ddis[index] + mmap[index][u]) {
                    mpre[u].clear();
                    mpre[u].push_back(index);
                    ddis[u] = ddis[index] + mmap[index][u];
                }
                else if (ddis[u] == ddis[index] + mmap[index][u]) mpre[u].push_back(index);
            }
        }
    }
}

void dijkstra2(int x) {
    memset(vis,false,sizeof vis);
    memset(tdis,inf,sizeof tdis);
    tdis[x] = 0;
    for (int i = 0; i < n; i++) {
        int Min = inf,index = -1;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && tdis[j] < Min) {
                Min = tdis[j];
                index = j;
            }
        }
        if (index == -1) return;
        vis[index] = true;
        for (int u = 0; u < n; u++) {
            if (!vis[u] && tmap[index][u] != inf) {
                if (tdis[u] > tdis[index] + tmap[index][u]) {
                    tpre[u].clear();
                    tpre[u].push_back(index);
                    tdis[u] = tdis[index] + tmap[index][u];
                }
                else if (tdis[u] == tdis[index] + tmap[index][u]) tpre[u].push_back(index);
            }
        }
    }
}

//有的dfs过程可以直接在 dijkstra模板里面直接完成
/* 就像这个样子
	for(int v = 0; v < n; ++v){
			if(visit[v] == false && e[u][v] != INF){
				if(e[u][v] + dis[u] < dis[v]){
					dis[v] = dis[u] + e[u][v];
					pre[v] = u;
					weight[v] = weight[u] + w[u][v];
                    //这样就不太需要dfs里面多重遍历了。
				}else if(e[u][v] + dis[u] == dis[v] && weight[u] + w[u][v] < weight[v]){
					weight[v] = weight[u] + w[u][v];
					pre[v] = u;
				}
			}
		}

*/
int mmin = 0x3f3f3f3f;
void dfs1(int x,int tmp) {
    if (x == _beg) {
        if (tmp < mmin) {
            mmin = tmp;
            mres = tempmres;
        }
        return ;
    }
    for (int i = 0; i < mpre[x].size(); i++) {
        tempmres.push_back(mpre[x][i]);
        dfs1(mpre[x][i], tmp + tmap[mpre[x][i]][x]);
        tempmres.pop_back();
    }
}

void dfs2(int x) {
    if (x == _beg) {
        if (temptres.size() < mmin) {
            mmin = temptres.size();
            tres = temptres;
        }
        return ;
    }
    for (int i = 0; i < tpre[x].size(); i++) {
        temptres.push_back(tpre[x][i]);
        dfs2(tpre[x][i]);
        temptres.pop_back();
    }
}

void show(const vector<int>&v) {
    for (int i = v.size() - 1; i >= 0; i--) {
            printf("%d",v[i]);
            if (i != 0) printf(" -> ");
        }
}

int main()
{
    scanf("%d %d",&n,&m);
    int a,b,s,l,t;
    memset(mmap,inf,sizeof mmap);
    memset(tmap,inf,sizeof tmap);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d %d %d", &a,&b,&s,&l,&t);
        mmap[a][b] = l;
        tmap[a][b] = t;
        if (s == 0) {
            mmap[b][a] = l;
            tmap[b][a] = t;
        }
    }
    scanf("%d %d",&_beg,&_end);
    dijkstra1(_beg);
    
    dijkstra2(_beg);
    tempmres.push_back(_end);
    dfs1(_end,0);
    temptres.push_back(_end);
    mmin = inf;
    dfs2(_end);
    if (mres == tres) {
        printf("Distance = %d; Time = %d: ",ddis[_end],tdis[_end]);
        show(mres);
    }
    else {
        printf("Distance = %d: ",ddis[_end]);
        show(mres);
        printf("\n");
        printf("Time = %d: ",tdis[_end]);
        show(tres);
    }

    return 0;
}