/*
	心态炸了 一道这么简单的水题，真的是边边角角的数据 好烦

    死在了 两个数相减 之后得到的数 可能小于4位数。

    崩溃。

    怕在考试的时候遇到像这样的题目，然后总是过不去满分，这样很烦人了。
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

bool cmp1(const char &a, const char &b) { return a > b; }
bool cmp2(const char &a, const char &b) { return a < b; }

int main()
{

    string tmp1, tmp2, s;
    cin >> s;
    for (int i = s.size(); i < 4; i++)
    {
        s.push_back('0');
    }
    tmp1 = tmp2 = s;
    int a, b, c;
    while (true)
    {
        sort(tmp1.begin(), tmp1.end(), cmp1);
        sort(tmp2.begin(), tmp2.end(), cmp2);
        a = stoi(tmp1);
        b = stoi(tmp2);
        c = a - b;

        if (c == 0)
        {
            printf("%04d - %04d = 0000", a, b);
            return 0;
        }
        string ss = to_string(c);
        for (int i = ss.size(); i < 4; i++)
            ss.push_back('0');
        tmp1 = tmp2 = ss;
        printf("%04d - %04d = %04d\n", a, b, c);
        if (c == 6174)
            break;
    }

    return 0;
}