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


int main()
{
	std::ios::sync_with_stdio(false);
	int a,b,c;
    cin >> a >> b;
    c = a + b;
    
    string s = to_string(c);
    
    int len = s.size();
    bool flag,res;

    if (s[0] == '-') {
        len = len - 1;
        cout << "-";
        int modf = len % 3;
        for (int i = 1; i < modf + 1; i++) {
            cout << s[i];
        }
        bool flag = true;
        for (int i = modf + 1; i + 2 < s.size(); ) {
            if (flag && modf == 0) {
                cout << s[i] << s[i + 1] << s[i + 2];
                flag = false;
            }
            else cout << "," << s[i] << s[i + 1] << s[i + 2];
            i = i + 3;
        }
    }
    else {
        int modf = len % 3;
        
        for (int i = 0; i < modf; i++) {
            cout << s[i];
        }
        bool flag = true;
        for (int i = modf; i + 2 < s.size(); ) {
            if (flag && modf == 0) {
                cout << s[i] << s[i + 1] << s[i + 2];
                flag = false;
            }
            else cout << "," << s[i] << s[i + 1] << s[i + 2];
            i = i + 3;
        }
    }


    return 0;
}