/*
	最后一个数据超时的原因估计就体现在了，递归层数，递归层数，如果过于大了，那么时间一定会超

    用大佬所说的话 就是：

    它特别限制了你的层数 
我们知道，dfs的时间复杂度是n！ 
如果n为1000，第5层需要t的时间来判断，那么你第六层就需要1000t的时间来判断！ 
如果用dfs，很显然，你是要多判断一层数据是不是在题目所给的层数限制范围内 
而bfs呢，你在遇到第一个超过层数的数据的时候，直接break，省下了1000t的时间
所以这里用bfs写一遍 具体考虑清楚 dfs 与 bfs可以相互转化的地方。
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
int n,l,k;

vector<int>v[1005];
bool vis[1005];

int total;
void dfs(int x,int cnt) {
    //在递归里面无论什么顺序都是很重要的
    //这里 只要进入下一层递归就直接标记清楚，代表这个人已经转发过了，不能不标记
    
    if (cnt == l) return;
    
    for (int i = 0; i < v[x].size();i++) {
        if (!vis[v[x][i]]){
            vis[v[x][i]] = true;
            total++;
        }
        //首先这里vis 是记录 是否看过，而不是是否转发过
        //如果要记录是否转发过的状态的话，会出现情况就是在不同路径里，某一个人是最后一层
        //而某一个人不是最后一层，这样就造成对于记录数组的困扰
        dfs(v[x][i], cnt + 1);
        //另外放在外面的第二个原因就在于，如果 我倒最后一层到达了 5 就把5给标记了，然后我其他的路径，
        //5 这个位置我可以继续去递归层数，由于前面已经将5给标记了，所以这里有问题了。
        //最主要的原因就是共享了一套底层数组。
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> l;
    int x,y;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        for (int j = 0; j < x; j++) {
            cin >> y;
            v[y].push_back(i);
        }
    }

    cin >> k;
    for (int i = 0; i < k; i ++) {
        memset(vis,false,sizeof vis);
        total = 0;
        cin >> x;
        vis[x] = true;
        dfs(x,0);
        cout << total<< endl;
    }

    return 0;
}