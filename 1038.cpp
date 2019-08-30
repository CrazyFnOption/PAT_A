/*
	这道题 是一道好题，完全没有往这个方面去考虑

    原来对于sort里面的排序还可以这个样子进行。

    直接将每一个 a + b < b + a
    这样样子去比较 看哪一位是最小的  记住了
    并且需要记住的是 特殊情况 当每一个数都是0的时候该怎么解决题目
*/
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

const int maxn = 1e4 + 5;
string s[maxn];

bool cmp (const string &a,const string &b) {
    return a + b < b + a;
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
    int n;
    cin >> n;
    string tmp;
    for (int i = 0; i < n;i ++) {
        cin >> s[i];
    }
    sort(s,s+n,cmp);
    
    int tt = stoi(s[n - 1]);
    if (tt == 0) {
        cout << 0 << endl;
        return 0;
    }

    tt = stoi(s[0]);
    cout << tt;
    for (int i = 1; i < n; i++) {
        cout << s[i];
    }
    cout << endl;
    
	
    return 0;
}