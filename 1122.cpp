/*
	本来以为是一道难题需要遍历题目中每一个点，我承认开始写这道题的时候，
    我个人有点慌了，有点不太弄清楚上面所说的内容了
    题目上面有解释哈密顿回路的意思。
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#define INF 0x3f3f3f3f

using namespace std;

const int maxn = 205;
typedef long long ll;
int n, m, mapp[maxn][maxn], k, path[maxn * 2];
bool used[maxn * 2];

bool Judge(int z)
{
    int num = 0;
    for (int i = 0; i < z; i++)
        if (!used[path[i]])
            used[path[i]] = true, num++;
    return num == n && z == n + 1;
}
int main()
{
    int x, y, z;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &x, &y);
        mapp[x][y] = mapp[y][x] = 1;
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &z);
        memset(used, false, sizeof(used));
        for (int j = 0; j < z; j++)
            scanf("%d", path + j);
        bool flag = true;
        if (path[0] == path[z - 1] && Judge(z))
        {
            for (int j = 1; j < z; j++)
            {
                if (mapp[path[j]][path[j - 1]] == 0)
                {
                    flag = false;
                    break;
                }
            }
        }
        else
        {
            flag = false;
        }
        if (flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}