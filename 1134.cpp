/*
	只有一个想法  卧槽 这都能过  我完全就是用全暴力的办法去做这样一道题，但是到最后竟然都过了，我就觉得特别的神奇
    本来以为一定会超时的，没想到竟然真的过了。
    去看一下题解 看看题解所使用的办法
    题解的想法跟我的思路差不多 直接去计算相应的边 是否有多余的边  不过前面不一样的地方就在于 他只记录边，每一个不一样的边

    很好的思路 只不过没想到这道题竟然是被这样写出来的
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

int n,m,k,t,x;
vector<pair<int,int> >v;

int main()
{
    scanf("%d %d",&n,&m);
    int a,b;
    for (int i = 0; i < m; i++) {
        scanf("%d %d",&a,&b);
        v.push_back(make_pair(a,b));
    }
    scanf("%d",&k);
    for (int i = 0; i < k; i++) {
        scanf("%d",&t);
        set<int>s;
        bool flag = true;
        for (int j = 0; j < t; j++) {
            scanf("%d",&x);
            s.insert(x);
        }
        for (int u = 0; u < v.size(); u++) {
            auto it1 = s.find(v[u].first);
            auto it2 = s.find(v[u].second);
            if (it1 == s.end() && it2 == s.end()) {
                flag = false;
                cout << "No" << endl;
                break;
            }
        }
        if (flag) cout << "Yes" << endl;
    }


    return 0;
}