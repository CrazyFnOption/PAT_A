/*
	直接暴力,一般20分的题目就是这样直接暴力得出来的
*/
#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>
using namespace std;
bool islegal(string s);
double tran(string s);
int main()
{
    int n;
    cin >> n;
    string s;
    double res = 0.0;
    int num = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> s;
        if (islegal(s))
        {
            double x = tran(s);
            if (x >= -1000 && x <= 1000)
            {
                num++;
                res += tran(s);
            }
            else
            {
                cout << "ERROR: " << s << " is not a legal number" << endl;
            }
        }
        else
        {
            cout << "ERROR: " << s << " is not a legal number" << endl;
        }
    }
    if (num == 0)
    {
        printf("The average of 0 numbers is Undefined");
    }
    else if (num == 1)
    {
        printf("The average of 1 number is %.2f", res);
    }
    else
    {
        printf("The average of %d numbers is %.2f", num, res / num);
    }
    system("pause");
    return 0;
}
double tran(string s)
{
    double sum = 0;
    bool f = 0;
    int pos = s.size() - 1;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '-')
        {
            f = 1;
            continue;
        }
        if (s[i] == '.')
        {
            pos = i;
            continue;
        }
        sum *= 10;
        sum += (s[i] - '0');
    }
    if (f)
        sum = -sum;
    sum /= pow(10, s.size() - 1 - pos);
    return sum;
}
bool islegal(string s)
{
    int pos = s.size() - 1;
    int num = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '.' || s[i] >= '0' && s[i] <= '9' || s[i] == '-' && i == 0)
        {
            if (s[i] == '.')
            {
                pos = i;
                num++;
            }
        }
        else
            return 0;
    }
    if (num > 1)
        return 0;
    if (s.size() - 1 - pos > 2)
        return 0;
    return 1;
}