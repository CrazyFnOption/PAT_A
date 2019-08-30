/*
	这种方法是错误的，因为如果这样存储的话，一定会造成内存爆的情况
    但是如果用二分法的话，那么存储的东西就不需要那么多
*/
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

const int maxn = 1e5 + 10;
int num[maxn];
vector<int> v[maxn];
bool res = false;
vector<pair<int, int> > vv;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    num[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
        num[i] += num[i - 1];
    }
    int Min = 0x3f3f3f3f;
    for (int i = 0; i <= n; i++)
    {
        int ans = 0;
        for (int j = i + 1; j <= n; j++)
        {
            ans = num[j] - num[i];
            v[i].push_back(ans);
            if (ans == k)
                vv.push_back(make_pair(i + 1, j));
            if (ans > k)
            {
                Min = min(ans, Min);
                break;
            }
        }
    }

    if (!vv.empty())
    {
        for (int i = 0; i < vv.size(); i++)
        {
            cout << vv[i].first << "-" << vv[i].second << endl;
        }
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            if (v[i][j] == Min)
            {
                cout << i << "-" << i + j << endl;
            }
        }
    }

    return 0;
}