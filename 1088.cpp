/*
	分数的四则运算，有点小复杂，到时候可以花点时间来做一下
*/
#include <iostream>
using namespace std;
typedef long long ll;

ll a, b, c, d, gcdvalue;

ll gcd(ll a, ll b)
{
    return b == 0 ? abs(a) : gcd(b, a % b);
}

string stringFormat(ll a, ll b)
{
    string res = "";
    gcdvalue = gcd(a, b);
    a /= gcdvalue;
    b /= gcdvalue;
    if (a * b < 0)
        res += "(-";
    ll c = abs(a), d = abs(b);
    if (c / d == 0)
    {
        if (c % d == 0)
            res += "0";
        else
            res += to_string(c) + "/" + to_string(d);
    }
    else
    {
        res += to_string(c / d);
        if (c % d != 0)
        {
            res += " " + to_string(c % d) + "/" + to_string(d);
        }
    }
    if (a * b < 0)
        res += ")";
    return res;
}

int main()
{
    scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
    ll sum1, sum2, sub1, sub2, mul1, mul2, div1, div2;
    //sum
    sum1 = a * d + b * c;
    sum2 = b * d;
    sub1 = a * d - b * c;
    sub2 = b * d;
    mul1 = a * c;
    mul2 = b * d;
    div1 = a * d;
    div2 = b * c;
    string a1 = stringFormat(a, b);
    string a2 = stringFormat(c, d);
    cout << a1 << " + " << a2 << " = " << stringFormat(sum1, sum2) << endl;
    cout << a1 << " - " << a2 << " = " << stringFormat(sub1, sub2) << endl;
    cout << a1 << " * " << a2 << " = " << stringFormat(mul1, mul2) << endl;
    if (a2 != "0")
        cout << a1 << " / " << a2 << " = " << stringFormat(div1, div2) << endl;
    else
        cout << a1 << " / " << a2 << " = "
             << "Inf" << endl;
}