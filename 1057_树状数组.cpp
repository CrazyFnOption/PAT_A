/*
	这道题使用 树状数组的原因是要使用二分查找，树状数组可以直接求解区间内的和，
    然后通过和来求解二分查找找到最中间的哪一个

    这道题 最好自己再写一遍，就当是熟悉一下树状数组的代码了

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
#include <stack>

using namespace std;

const int maxn = 1e5 + 10;

int tree[maxn];

int lowbit(int x) {
    return x & (-x);
}

void update(int x,int val) {
    while (x <= maxn) {
        tree[x] += val;
        x += lowbit(x);
    }
}

int getsum(int x) {
    int res = 0;
    while (x > 0) {
        res += tree[x];
        x -= lowbit(x);
    }
    return res;
}

//可能第一次遇到二分法还可以这样用
//以前想到的二分法都是使用，相应的值进行排序之后去找中间或者某一个值
//然后这道题就是使用坐标来进行标记，如果50这个位置有数的话，那么久在50这个位置记上一个1就可以了
//如果要增减的话，就直接在数上面进行增减，然后根据树状数组来计算相应的和，来找中间的数，真的是神奇。
void peekmedian(int k) {
    int l = 1,r = maxn - 1;
    int mid;
    //二分查找这里不要再写错了...
    while (l < r) {
        mid = (l + r) / 2;
        if (getsum(mid) >= k) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
}


int n;
string s;
stack<int> ss;

int main()
{
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s == "Pop") {
            if (ss.empty()) {
                cout << "Invalid" << endl;
                continue;
            }
            tmp = ss.top();
            ss.pop();
            update(tmp,-1);
            cout << tmp << endl;
        }
        else if (s == "Push") {
            cin >> tmp;
            ss.push(tmp);
            update(tmp,1);
        }
        else {
            if (ss.empty()) {
                cout << "Invalid" << endl;
                continue;
            }
            int x = ss.size();
            peekmedian((x + 1) / 2);
        }
    }

    return 0;
}