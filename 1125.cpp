/*
	还是一道简单的水题  不过需要记住三个函数  这里今年果然是不嫩更超过其的最大常数 意思就是向下取整
    round 四舍五入
    floor 向下取整
    cell 向上取整
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
#include <functional>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    double num[10005];
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num,num+n);
    double res = num[0];
    for (int i = 1; i < n; i++) {
        res += num[i];
        res = res / 2;
    }
    cout << floor(res) << endl;
}