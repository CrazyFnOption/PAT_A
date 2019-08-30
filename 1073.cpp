/*
	简单的一道模拟题目 但是某些步骤以及相应逻辑 有点小复杂
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

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    char symbol = s[0];
    string res;
    int x;
    int i;
    if (symbol == '-') cout << symbol;
    for (i = 1; i < s.size(); i++) {
        if (s[i] == '.') continue;
        if (s[i] == 'E') break;
        res.push_back(s[i]);
    }
    //cout << res << endl;
    i++;
    x = stoi(s.substr(i + 1, s.size()));
    if (s[i] == '+') {
        int y = x - (res.size() - 1) ;
        if (y >= 0) {
            for (int i = 0; i < y; i++) res.push_back('0');
            cout << res;
            return 0;
        }
        else {
            res.insert(x + 1,".");
            cout << res;
            return 0;
        }
    }

    int y = x - 1;
    if (y == -1) {
        res.insert(1,2,'.');
        cout << res;
        return 0;
    }
    cout << "0.";
    for (int i = 0; i < y; i++) cout << '0';
    cout << res ;
    
    return 0;
}