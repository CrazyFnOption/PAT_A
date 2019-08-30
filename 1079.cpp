/*
	有一个样例时间会超，我觉得可能就是因为不需要重复计算这么多次，直接算出来每一个节点多少钱就行了，不需要每一次都回到最上面的点

    以后有时间可以写一下，这道题算是一道简单的题目，可以用dfs或者bfs
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

int n;
double p,r;

int v[100005];
vector<pair<int,int> >res;
int main()
{
    
    scanf("%d %lf %lf",&n,&p,&r);
    r = r / 100;
    int a,b;
    double sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d",&a);
        if (a == 0) {
            scanf("%d",&b);
            res.push_back(make_pair(i,b));
            continue;
        }
        for (int j = 0; j < a; j++) {
            scanf("%d",&b);
            v[b] = i;
        }
    }
    for (int i = 0; i < res.size(); i++) {
        int id = res[i].first;
        int number = res[i].second;
        int cnt = 0;
        while (id != 0) {
            id = v[id];
            cnt++;
        }
        sum += p * pow(1 + r,cnt) * number;
    }
    printf("%.1lf",sum);
    return 0;
}