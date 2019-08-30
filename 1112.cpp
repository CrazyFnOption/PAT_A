/*
	这道题后面感觉一下 自己有点想复杂了，只需要保证每一个重复的是其的整数倍就可以了

    自己有时间改一下自己错误代码
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

using namespace std;

string s;
int n;
set<char>res;
map<char,bool> m;
int cnt;
bool check (char ch,int pos) {
    for (int i = pos + 1; i < pos + n;i ++) {
        if (i >= s.size()) {
            cnt = s.size() + 1;
            return false;
        }
        if (s[i] != ch) {
            cnt = i;
            return false;
        }
    }
    cnt = pos + n;
    return true;
}

int main()
{
    
    cin >> n;
    //这个地方必须getchar一下 保证不会被吞掉
    getchar();
    getline(cin,s);
    char last,ch;
    for (int i = 0;i < s.size(); ) {
        ch = s[i];
        if (check(ch,i)) {
            m[ch] = true;
            res.insert(ch);
            s.erase(i,n - 1);
            i++;
            
            
        }
        else {
            m[ch] = false;
            i = cnt;
        }
        
    }

    
    for (auto it = res.begin(); it != res.end(); it++) {
        if (m[*it]) cout << *it;
    }
    cout << endl;
    cout << s << endl;

    return 0;
}