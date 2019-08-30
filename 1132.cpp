/*
	简直侮辱智商的一道题 不过要记住 在mod时候  b 不能等于0
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
    int n;
    cin >> n;
    string s;
    while (n--) {
        cin >> s;
        string a = s.substr(0,s.size() / 2);
        string b = s.substr(s.size() / 2, s.size());
        long long x = stoll(s);
        long long a_ = stoll(a);
        long long b_ = stoll(b);
        if (b_ == 0) {
            cout << "No" << endl;
            continue;
        }
        if (x % a_ == 0 ){
            long long y = x / a_;
            if (y % b_ == 0) {
                cout << "Yes" << endl;
                continue;
            }
        }
         cout << "No" << endl;
    }
    return 0;
}