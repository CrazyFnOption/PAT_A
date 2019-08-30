/*
	如此简单的一道题 简直侮辱我的智商
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

vector<string>v;
vector<string>res;
map<string,bool>mm;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int m,n,s;
    cin >> m >> n >> s;
    string x;
    for (int i = 0;i < m; i++) {
        cin >> x;
        v.push_back(x);
        mm[x] = true;
    }

    if (s - 1 > n) {
        cout << "Keep going..." << endl;
        return 0;
    }

    for (int i = s - 1; i < v.size();i ++) {
        if (mm[v[i]]) {
            res.push_back(v[i]);
            mm[v[i]] = false;
            i = i + n - 1;
        }
    }
    for (int i = 0;i < res.size(); i++) {
        cout << res[i] << endl;
    }

    return 0;
}