/*
	这道题在处理数字的中文化上面很聪明，成功利用了数字在全部 从十 百 千 万 这一系列的变化 很厉害

    这个逻辑过程值得在做一遍
*/
#include <iostream>
#include <cstdio>
using namespace std;
string digit[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
string bit[10] = {"", "Shi", "Bai", "Qian", "Wan", "Shi", "Bai", "Qian", "Yi"};
string t;
int main()
{
    cin >> t;
    int i;
    for (i = 0; i < t.length() - 1; ++i)
    {
        if (t[i] == '-')
        {
            cout << "Fu";
            continue;
        }
        //对于0情况的处理
        if (t[i] == '0')
        {
            if (t.length() - i == 5 && (t.length() < 9 || t[i - 1] + t[i - 2] + t[i - 3] > 3 * '0'))
            { //在万位

                cout << " "
                     << "Wan"; //十万、百万、千万
            }
            else if (t[i + 1] != '0')
            {
                cout << " "
                     << "ling";
            }
        }
        else
        {
            if (i)
                cout << " ";
            cout << digit[t[i] - '0'] << " " << bit[t.length() - 1 - i];
        }
    }
    if (t[i] != '0')
        cout << " " << digit[t[i] - '0'];
    else if (t.length() == 1 && t[0] == '0')
        cout << "ling"; // case:0
    return 0;
}
