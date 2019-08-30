/*
	这道题很神奇，我到现在还不能理解 为什么将vector 改成 string 就错了，用的都是一模一样的函数

    不过现在想了下  的确是不能使用字符串进行转换，因为如果超出了十进制，想要将几位数表现成一个字符的话就有点难度了

    总结 十进制以内的转换可以使用string

    但是超过十进制的转换的话 就需要好好注意一下了。
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

int n, radix;



int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> radix;
    vector<int> ss;
    while (n > 0) {
        ss.push_back(n % radix);
        n = n / radix;
    }

    vector<int> tmp(ss.rbegin(),ss.rend());
    
    if (tmp == ss) {
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;

    cout << tmp[0];

    for (int i = 1; i < tmp.size();i++)
        cout << " " << tmp[i];
    return 0;
}