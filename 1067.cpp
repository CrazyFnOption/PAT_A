/*
	这个地方就是错误代码，这里是运行有两个点是超时，思路都一样，就是尽量让每次交换最大化，意思就是
    每一次交换都有它的价值，换到对的地方上面，

    但是超时的问题就在于每一次都要遍历大部分数组，然后判断其是否符合题目要求

    所以真正正确的做法应该是存入数组的位置 而不是数组的数值  看其的ac代码

    存入位置，直接去交换位置，可以避免很多问题  是一道好题。

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
int num[100005];



int main()
{
    
    scanf("%d",&n);
    int pos;
    for (int i = 0; i < n; i++) {
       scanf("%d",&num[i]);
        if (num[i] == 0) pos = i;
    }

    int cnt = 0;
    int i = 0;
    bool flag = false;
    while (true) {
        if (pos == 0) {
            flag = false;
            for (i = 0; i < n; i++) {
                if (num[i] != i) {
                    cnt++;
                    swap(num[i],num[pos]);
                    swap(i,pos);
                    flag = true;
                    break;
                }
            }
            if (flag) continue;
            else break;
        }
        for (; i <= n; i++) {
            if (num[i] == pos) {
                cnt++;
                swap(num[i],num[pos]);
                swap(i,pos);
                i = 0;
                break;
            }
        }
    }
    
    printf("%d",cnt);
    return 0;
}