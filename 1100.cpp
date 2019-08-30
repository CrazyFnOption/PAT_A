#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define STP system("pause")
#pragma warning(disable : 4996)

int main()
{
    int M, N, index;
    string str, str1;
    cin >> M;

    string a[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"}; //个位数字
    string b[12] = {"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};         //十位数字
    for (int i = 0; i < M; i++)
    {
        cin >> str;
        if (isdigit(str[0]))
        {
            int data = stoi(str);
            int m = data % 13; //个位
            int n = data / 13; //十位
            n--;
            if (n < 0)
                cout << a[m] << endl;
            else
            {
                if (m == 0)
                {
                    cout << b[n] << endl;
                }
                else
                {
                    cout << b[n] << " " << a[m] << endl;
                }
            }
        }
        else
        {
            if (cin.get() != '\n')
            {
                cin >> str1;
                int it = find(b, b + 12, str) - b + 1;
                int it1 = find(a, a + 13, str1) - a;
                cout << it * 13 + it1 << endl;
            }
            else
            {
                if ((find(a, a + 13, str) - a) == 13) //个位中没有找到
                {
                    int it = find(b, b + 12, str) - b + 1;
                    cout << it * 13 << endl;
                }
                else
                {
                    int it1 = find(a, a + 13, str) - a;
                    cout << it1 << endl;
                }
            }
        }
    }

    STP;
    return 0;
}