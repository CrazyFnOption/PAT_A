/*
	非诚简单的的一道题目咯
*/
#include <iostream>
#include <map>
#include <stdio.h>
using namespace std;
int main()
{
    int m, n, x;
    scanf("%d %d", &m, &n);
    int colornum = 0, color = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            scanf("%d ", &x);
            if (colornum == 0)
            {
                color = x;
            }
            if (color == x)
            {
                colornum++;
            }
            else
            {
                colornum--;
            }
        }
    }
    printf("%d", color);
    system("pause");
    return 0;
}