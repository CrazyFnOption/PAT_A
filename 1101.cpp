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

const int maxn = 1e6 + 20;

long num[maxn];
long pos[maxn];
vector<int>v;

int main()
{
    int n;
    scanf("%d",&n);
    
    for (int i = 0; i < n; i++) {
        scanf("%ld",&num[i]);
        pos[i] = num[i];
    }
    v.clear();
    int Max = -1;
    sort(pos,pos + n);
    //思路上是对了一半，但是考虑错了一种情况，比如说
    //样例    51243 
    //正确顺序12345 应该是没有主元，而不是有一个主元
    //所以问题在于要比较当前位置的最大值
    for (int i = 0; i < n; i++) {
        if (num[i] > Max) Max = num[i];
        if (pos[i] == num[i] && num[i] >= Max) {
            v.push_back(pos[i]);
        }
    }
    //这里出现一个问题就在于可能没有主元的问题上，如果没有主元就不能直接输出v[0]了
    int res = v.size();
    printf("%d\n",res);
    for (int i = 0; i < res; i++) {
        printf("%d",v[i]);
        if (i < res - 1) printf(" ");
    }
    cout << endl;
    
}