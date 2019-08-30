/*
	本来以为要什么特殊操作 才不会超时，没想到这都能过 真的是太扯了。
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
const int maxn = 50005;

int pre[maxn];
int in[maxn];
int n;

vector<int>res;

void dfs(int lpre,int rpre,int lin,int rin) {
    if (lin > rin || !res.empty()) return ;
    int i = lin;
    while (pre[lpre] != in[i] && i <= rin) i++;
    dfs(lpre + 1,lpre + i - lin,lin,i - 1);
    dfs(lpre + i - lin + 1,rpre,i + 1,rin);
    res.push_back(pre[lpre]);
}

int main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) scanf("%d",&pre[i]);
    for (int i = 1; i <= n; i++) scanf("%d",&in[i]);
    dfs(1,n,1,n);
    cout << res[0] << endl;

    return 0;
}