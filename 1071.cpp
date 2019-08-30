/*
	这个以后有时间写一遍吧 
    主要是记住几个函数 
    isalnum
    tolower

    还是要一个一个字符去处理，要不然的话就特别麻烦。
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
#include <sstream>

using namespace std;

int main()
{
    map<string,int>m;
    int Max = -1;
    string ss,t,y;
    vector<string>v;
    getline(cin,ss);
    stringstream s(ss),x;


    while (s >> t) {
        //stringstream 在处理字符的时候 清空只能用clear
        x.clear();
        for (int i = 0; i < t.size(); i++) {
            if (t[i] >= '0' && t[i] <= '9') {
                x << t[i];
                continue;
            }
            if (t[i] >= 'a' && t[i] <= 'z') {
                x << t[i];
                continue;
            }
            if (t[i] >= 'A' && t[i] <= 'Z') {
                t[i] = tolower(t[i]);
                x << t[i];
                continue;
            };
            x << ' ';
        }
        while (x >> y) {
            m[y]++;
        }
    } 
    for (auto it = m.begin(); it != m.end(); it++) {
        if (Max < it->second) {
            Max = it->second;
            ss = it->first;
        }
    }
    cout << ss << " " << Max << endl;
    return 0;
}