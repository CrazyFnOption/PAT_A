
/*
	这道题是真的被自己蠢哭了，直接标记就可以了....

    干嘛还要自己去模拟 去实现...

    太蠢了额。

    哎 被自己蠢哭了
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

map<char,bool> m;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    m.clear();
    for (int i = 0; i < s2.size(); i++) {
        m[s2[i]] = true;
    }
    for (int i = 0; i < s1.size(); i++) {
        if (!m[s1[i]]) cout << s1[i];
    }
    cout << endl;

    return 0;
}