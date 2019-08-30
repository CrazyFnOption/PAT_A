/*
	这种办法连树都不需要去建立，直接童年各国二叉树的性质去写出来就可以了
*/
#include <cstdio>
#include <vector>
#include <map>
using namespace std;
int main()
{
    int m, n;
    map<int, bool> mp;
    scanf("%d %d", &m, &n);
    vector<int> pre(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pre[i]);
        mp[pre[i]] = true;
    }
    int u, v;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        int a;
        for (int j = 0; j < pre.size(); j++)
        {
            a = pre[j];
            if ((a < u && a > v) || (a > u && a < v) || (a == u) || (a == v))
            {
                break;
            }
        }
        if (mp[u] == false && mp[v] == false)
        {
            printf("ERROR: %d and %d are not found.\n", u, v);
        }
        else if (mp[u] == false || mp[v] == false)
        {
            printf("ERROR: %d is not found.\n", mp[u] == false ? u : v);
        }
        else if (a == u || a == v)
        {
            printf("%d is an ancestor of %d.\n", a, a == u ? v : u);
        }
        else
        {
            printf("LCA of %d and %d is %d.\n", u, v, a);
        }
    }
    return 0;
}