/*
	就是一个简单的题目换算问题，这里出现的问题就是 注意如果不足两位的话记住要补上0

    不过就上2位的13进制转换 简单题
*/
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
string t = "0123456789ABC";
int main()
{
    int n;
    printf("#");
    for (int i = 0; i < 3; ++i)
    {
        scanf("%d", &n);
        printf("%c%c", t[n / 13], t[n % 13]);
    }
    return 0;
}

