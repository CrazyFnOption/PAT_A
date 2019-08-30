/*
	求解最大公约数与最小公倍数的裸题，题目还算是简单

    不过不要忘记了最大公约数与最小公倍数的写法
*/

#include <iostream>
#include <cstdio>
using namespace std;

long int gcd(long int a, long int b)
{
    // assume that the input satisfies a > b
    if (b < 0)
    {
        b = b * (-1);
    }
    long int r;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int N;
    long int up = 0, down = 1;
    long int remainder, gcdVal = 0;
    long int integer = 0, numerator = 0, denominator = 0;
    cin >> N;
    long int *a = new long int[N];
    long int *b = new long int[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%lld/%lld", &a[i], &b[i]);
    }
    for (int i = 0; i < N; i++)
    {
        down *= b[i];
    }
    for (int i = 0; i < N; i++)
    {
        up += a[i] * (down / b[i]);
    }
    if (up == 0)
    {
        cout << "0" << endl;
        return 0;
    }
    integer = up / down;
    remainder = up % down;
    if (remainder != 0)
    {
        gcdVal = gcd(down, remainder);
        numerator = remainder / gcdVal;
        denominator = down / gcdVal;
    }
    // output, pay attention to the format
    if (integer != 0 && numerator != 0)
    {
        cout << integer << " " << numerator << "/" << denominator;
    }
    else if (numerator == 0)
    {
        cout << integer;
    }
    else if (integer == 0)
    {
        cout << numerator << "/" << denominator;
    }
    cout << endl;
    return 0;
}