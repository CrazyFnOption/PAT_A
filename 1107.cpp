/*
	看着题目还挺吓人的  冷静下来 一发ac 

    觉得还挺简单的，主要是这种题目需要多注意一下题面。
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
#include <set>

using namespace std;

int n,x,t;
vector<int>hobby[1005];
vector<int>people[1005];
bool vis[1005];
int num[1005];

void dfs(int tot,int x) {
    if (vis[x]) return;
    vis[x] = true;
    num[tot]++;
    for (int i = 0; i < people[x].size(); i++) {
        int u = people[x][i];
        for (int j = 0; j < hobby[u].size(); j++) {
            dfs(tot,hobby[u][j]);
        }
    }
}

bool cmp (int a, int b) {return a > b;}

int main()  
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) {
        scanf("%d:",&x);
        for (int j = 0; j < x; j++) {
            scanf("%d",&t);
            hobby[t].push_back(i);
            people[i].push_back(t);
        }
    }
    int tot = 0;
    for (int i = 1;i <= n; i++) {
        if (!vis[i]) {
            dfs(tot,i);
            tot++;
        }
    }
    sort(num,num + tot,cmp);
    printf("%d\n",tot);
    for (int i = 0; i < tot; i++) {
        printf("%d",num[i]);
        if (i != tot - 1) printf(" ");
    }

    return 0;
}