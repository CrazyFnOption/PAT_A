/*
	卧槽 这道题 看了下题解是一道简单题  我自己的做法 超时了三个数据 所以只有15分

    这道题考到了 组合原理 根据计算t的个数和p的个数，然后来计算a的个数有多少个 然后再相加起来

    神奇的题目
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

string s;

const long mod = 1000000007;
char ch;



int main()
{
    long long res = 0;
    cin >> s;
    int pcnt = 0,tcnt = 0;
    for (int i = 0; i < s.size();i ++) {
        if (s[i] == 'T') tcnt++;
    }

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'T') tcnt--;
        else if (s[i] == 'P') pcnt++;
        else res = (res + tcnt * pcnt % mod) % mod;
    }

    

    printf("%lld",res);
    return 0;
}