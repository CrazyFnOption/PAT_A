/*
	真心觉得对于做题 英文能力真的好重要 要回去好好学习英语了 
    
    这道题很简单 难就难在理解题目意思上面了
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

bool cmp (int a,int b) {
    return a > b;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int num[n + 5];
    for (int i = 0;i < n; i++) {
        cin >> num[i];
    }
    sort(num,num+n,cmp);
    int cnt = 0;
    while (num[cnt] > cnt + 1 && cnt < n) cnt++;
    cout << cnt << endl;

    return 0;
}