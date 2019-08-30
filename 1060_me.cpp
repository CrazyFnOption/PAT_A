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

int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    string a, b;
    cin >> n >> a >> b;
    while (a.size() != 0 && a[0] == '0') a.erase(a.begin());
    while (b.size() != 0 && b[0] == '0') b.erase(b.begin());
    int lena = -1, lenb = -1;
    for (int i = 0; i < a.size(); i++)
        if (a[i] == '.')
        {
            lena = i;
            break;
        }
    for (int i = 0; i < b.size(); i++)
        if (b[i] == '.')
        {
            lenb = i;
            break;
        }
    if (lena == -1)
        lena = a.size();
    if (lenb == -1)
        lenb = b.size();

    int Min = min(a.size(), b.size());
    int Max = max(a.size(), b.size());

    if (a == "0" || b == "0")
    {
        if (a == b)
            cout << "YES "
                 << "0";
        else
        {
            cout << "NO ";
            if (a == "0")
            {
                if (b[0] == '0')
                {
                    cout << b.substr(0, n + 2) << "*10^" << 0;
                }
                else
                    cout << "0." << b.substr(0, n) << "*10^" << lenb << " ";
            }
            else
            {

                if (a[0] == '0')
                {
                    cout << a.substr(0, n + 2) << "*10^" << 0 << " ";
                }
                else
                    cout << "0." << a.substr(0, n) << "*10^" << lena << " ";
            }
        }
        return 0;
    }
    bool flag = true;
    int cnt = 0;
    if (a[0] == '0' && b[0] == '0')
        cnt = 2;
    for (int i = cnt; i < n + cnt  + cnt; i++)
    {
        if (a[i] != b[i])
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        if (a[0] == '0')
        {
            lena = lenb = 0;
            cout << "YES "
                 << "0." << a.substr(2, n) << "*10^" << max(lena, lenb);
        }
        else
            cout << "YES "
                 << "0." << a.substr(0, n) << "*10^" << max(lena, lenb);
    }
    else
    {
        cout << "NO ";

        if (a[0] == '0')
        {
            cout << a.substr(0, n + 2) << "*10^" << 0 << " ";
        }
        else
            cout << "0." << a.substr(0, n) << "*10^" << lena << " ";

        if (b[0] == '0')
        {
            cout << b.substr(0, n + 2) << "*10^" << 0;
        }
        else
            cout << "0." << b.substr(0, n) << "*10^" << lenb;
    }

    return 0;
}