/*
	这道题算是一道好题，只不过 我没有太多思路，这道题容易将我的思路弄炸，所以毋庸置疑，这道题我得自己再写一遍

*/
#include <iostream>
#include <cmath>
using namespace std;
long int num, temp;
int main()
{
    cin >> num;
    int first = 0, len = 0, maxn = sqrt(num) + 1;
    //这里所奉行的思路，就是利用其的上界限一定是 sqrt(num)以下。
    //在此之下一定要求从每一个开始连续相乘，然后分别计算相乘所得到的结果是不是
    //这个数的因子，如果是的话，求取最长的哪一个
    for (int i = 2; i <= maxn; i++)
    {
        int j;
        temp = 1;
        for (j = i; j <= maxn; j++)
        {
            //这个里面就已经存在了判断质数的过程
            temp *= j;
            //这里只要有一个长度不能被整除，这个时候无论后面有多少个数出来相乘，都无法得到结果
            if (num % temp != 0)
                break;
        }
        //这里就直接去比较最后的长度结果
        if (j - i > len)
        {
            len = j - i;
            first = i;
        }
    }
    if (first == 0)
    {
        cout << 1 << endl
             << num;
    }
    else
    {
        cout << len << endl;
        for (int i = 0; i < len; i++)
        {
            cout << first + i;
            if (i != len - 1)
                cout << '*';
        }
    }
    return 0;
}