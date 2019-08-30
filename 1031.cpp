/*
	这道题算是一道简单题，一道找规律的题，在ACM里面就是签到题，
    找到规律就可以直接AC的题目，加油。

    不过简单题做出来给自己增加信心真的很不错。
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

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    int len , lenm;
    len = lenm = (s.size() + 2 ) / 3;
    lenm += (s.size() + 2) % 3;
    lenm -= 2;
    int k = 0;
    for (int i = 0; i < len - 1; i++) {
        printf("%c",s[k]);
        for (int j = 0; j < lenm;j ++) {
            printf(" ");
        }
        printf("%c\n",s[s.size() - 1 - k++]);
    }
    int l = s.size() - k;
    for (;k < l; k++) {
        printf("%c",s[k]);
    }
    

    return 0;
}