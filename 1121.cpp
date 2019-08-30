/*
	STL的运用，以及简单模拟，算是一道简单题目。
*/
#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main()
{
    int n, a, b, m;
    scanf("%d", &n);
    vector<int> couple(100000, -1);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &a, &b);
        couple[a] = b;
        couple[b] = a;
    }
    scanf("%d", &m);
    vector<int> guest(m), have(100000);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d", &guest[i]);
        if (couple[guest[i]] != -1)
            have[couple[guest[i]]] = 1;
    }
    set<int> s;
    for (int i = 0; i < m; i++)
        if (!have[guest[i]])
            s.insert(guest[i]);
    printf("%d\n", s.size());
    for (auto it = s.begin(); it != s.end(); it++)
    {
        if (it != s.begin())
            printf(" ");
        printf("%05d", *it);
    }
    return 0;
}