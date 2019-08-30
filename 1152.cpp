#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <stdlib.h>
using namespace std;
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    int sqr = (int)sqrt(1.0 * n);
    for (int i = 2; i <= sqr; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int main()
{
    int l, k, flag = 1;
    string s;
    cin >> l >> k >> s;
    for (int i = 0; i <= l - k; i++)
    {
        if (isPrime(atoi(s.substr(i, k).c_str())))
        {
            cout << s.substr(i, k) << "\n";
            flag = 0;
            break;
        }
    }
    if (flag == 1)
        cout << "404\n";
    return 0;
}
