#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<cstdio>
#include<queue>
#include<map>
#include<cmath>

using namespace std;

bool is(const string &a) {
    string s (a.rbegin(),a.rend());
    if (s == a) return true;
    return false;
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	string a;
    getline(cin,a);
    int len = a.size();
    
    int Max = -1;
    int res;
    
    string tmp;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len ;j++) {
            tmp = a.substr(i,j + 1);
            if (is(tmp)) {
                Max = max((int)tmp.size(),Max);
            }
        }
    }
    if (Max == -1) cout << 1 << endl;
    else cout << Max << endl;
    return 0;
}