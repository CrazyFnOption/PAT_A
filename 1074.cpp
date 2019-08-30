/*
	首先这道题是一道简单题，死在这道题的原因应该就是自己的逻辑组织能力有点弱吧...

    题目读错了然后一半的时间就没有，下回需要多花点时间去读题

    我他妈真是醉了

    这么简单的一道题 让我心力憔悴

    我总是喜欢去想底层实现，然后想的特别复杂。
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

const int maxn = 1e6 + 5;

struct Node {
    int data;
    int next;
    int address;
    int pre;
}node[maxn];

vector<int> res;

int main()
{
    int n,k,first;
    scanf("%d %d %d",&first,&n,&k);
    int a,b,c;
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        node[a].data = b;
        node[a].next = c;
        node[a].address = a;
        
    }
    while (true) {
        res.push_back(first);
        first = node[first].next;
        if (first == -1) break;
    }
    for (int i = 0; i + k <= res.size(); i += k) 
        reverse(res.begin() + i,res.begin() + i + k);
    int j;
    for (j = 0; j < res.size() - 1; j++)
        printf("%05d %d %05d\n", res[j], node[res[j]].data, res[j + 1]);
    printf("%05d %d -1\n", res[j], node[res[j]].data);
    return 0;
}