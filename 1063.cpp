/*
	也是一道简单题 一发直接ac stl的直接应用题一般都是水题。
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
#include <set>
#include <iomanip>

using namespace std;

set<int> s[52];

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,x,k,a,b;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> m;
        for (int j = 0; j < m; j++) {
            cin >> x;
            s[i].insert(x);
        }
    }

    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        int tp = s[a].size() + s[b].size();
        double tc = 0;
        set<int>::iterator it;
        for (auto i = s[b].begin(); i != s[b].end(); i++) {
            it = s[a].find(*i);
            if (it != s[a].end()) {
                tc++;
            }
        }
        cout << fixed << setprecision(1) << (tc / (tp - tc)) * 100.0 << "%" << endl;
    }
    return 0;
}