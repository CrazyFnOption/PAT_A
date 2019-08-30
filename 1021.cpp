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

const int maxn = 1e4 + 10;

int n;
int fa[maxn];
set<int> s;
vector<int>tree[maxn];
bool vis[maxn];
int Max;
int res[maxn];

void init() {
    for (int i = 0;i <= n; i++) {
        fa[i] = i;
    }
}

int _find(int x) {
    if (fa[x] == x) return x;
    return fa[x] = _find(fa[x]); 
}

void merge(int x,int y) {
    int fx = _find(x);
    int fy = _find(y);
    if (fx != fy) fa[fx] = fy;
    return;
}

void dfs(int x,int cnt) {
    vis[x] = true;
    //这个地方一定要有一个比较的过程，
    //要不然每次dfs的时候都会陷入一个奇怪的结果
    Max = max(Max,cnt);
    for (int i = 0; i < tree[x].size(); i++) {
        if (!vis[tree[x][i]]) dfs(tree[x][i],cnt+1);
    }
    return;
}

int main()
{
    
    scanf("%d",&n);
    init();
    int x,y;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d",&x,&y);
        merge(x,y);
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    //注意这个地方再写并查集的时候，要么 直接用 比较与初值是否相同
    /*
    就像这样
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (fa[i] == i) cnt++;
    }
     */

    //要么直接去写函数，不要写数组所代表的值。
    for (int i = 1; i <= n; i++) {
        s.insert(_find(i));
    }

    if (s.size() != 1) {
        cout << "Error: " << s.size() << " components" << endl;
        return 0;
    }
    int MMax = 0;
    for (int i = 1; i <= n; i++) {
        memset(vis,false,sizeof vis);
        Max = 0;
        dfs(i,1);
        res[i] = Max;
        MMax = max(MMax,Max);
    }

    for (int i = 1; i <= n; i++) {
        if (res[i] == MMax) cout << i << endl;
    }
    

    return 0;
}

//第二种直接通过dfs求取连通数的方法，上面则是采用的是并查集
/*
	void dfs1(int step)
{
	book[step]=1;
	for(int i=0;i<graph[step].size();i++)
	{
		if(!book[graph[step][i]])
		dfs1(graph[step][i]);	
	} 
}
*/