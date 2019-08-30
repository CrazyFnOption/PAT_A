/*
	算是一道简单题，但是前面有的问题就在于 这道题是不能够打表的

    好像是因为pat的题目都是单组输入，
    所以打表的话应该都不能算作是 节约时间，然后主要是这道题没有给你最大值的一个限制，

    所以造成的结果就是，很可能因为数组存不下去出现问题。

    另外这道题前面最好进行判断一下，这样可以节省如果直接是质数所耗费的时间。
*/
#include <iostream>
using namespace std;

bool isPrime(long long num)
{
    if (num < 2)
    {
        return false;
    }
    for (long long i = 2; i < num / 2 + 1; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    long long num;
    bool first = true;

    cin >> num;
    cout << num << "=";

    if (num < 2)
    {
        cout << num;
        return 0;
    }
    for (long long i = 2; i <= num; i++)
    {
        if (isPrime(i))
        {
            int cnt = 0;
            while (num % i == 0)
            {
                cnt++;
                num /= i;
            }
            if (cnt == 0)
            {
                continue;
            }
            if (first)
            {
                first = false;
            }
            else
            {
                cout << '*';
            }
            if (cnt == 1)
            {
                cout << i;
            }
            else
            {
                cout << i << '^' << cnt;
            }
        }
    }
    system("pause");
    return 0;
}