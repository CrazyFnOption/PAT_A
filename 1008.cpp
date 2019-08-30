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
    int n;
    cin >> n;
    int temp = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        if (t - temp > 0)
        {
            ans += (t - temp) * 6;
            temp = t;
        }
        else
        {
            ans += abs(t - temp) * 4;
            temp = t;
        }
    }
    cout << ans + n * 5;
    return 0;
}

