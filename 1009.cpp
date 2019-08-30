/*
	这道题数据有点水，一道水题，不过最后还是摆了我一道，问题就在于没有注意到最后相加为0，要从集合中剔除的办法。

    如果是我的话 我应该会 会设置一点 一位数为0的例子，比如说 0.01， 0.02 0.03 像这样的数据到后面题目里就直接为0 这里需要注意
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
#include <iomanip>

using namespace std;

const int maxn = 1e6 + 7;
double a[maxn],b[maxn],res[maxn];
set<int> sa,sb;
int x,y;
int tmp;
double tmp_2;

//这个就是set内部的自定义排序方法，可以在调用的时候更改，也可以封装一个类当做int类型
struct incmp {
    bool operator() (int a,int b) {
        return a > b;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);

    memset(a,0,sizeof a);
    memset(b,0,sizeof b);
    memset(res,0,sizeof res);

    set<int,incmp> sc;
    sc.clear();
    cin >> x;
    for (int i = 0; i < x; i++) {
        cin >> tmp >> tmp_2; 
        a[tmp] += tmp_2;
        sa.insert(tmp);
    }

    cin >> y;
    for (int i = 0; i < y; i++) {
        cin >> tmp >> tmp_2;
        b[tmp] += tmp_2;
        sb.insert(tmp);
    }

    int cnt = 0;
    double ans;
    for (auto i : sa) {
        for (auto j : sb) {
            ans = a[i] * b[j];
            if (ans != 0) {
                res[i + j] += ans;
                if (res[i + j] != 0)
                    sc.insert(i + j);
                else cnt++;
            }
        }
    }

    cout << sc.size() - cnt;

    //这里还是没有注意到 如果相加为0的情况，万一最后加法为0，那么就要从原来数组里面剔除了
    for (auto i : sc) {
        if(res[i] != 0)
        cout << " " << i  << " " << fixed << setprecision(1) <<  res[i];
    }
    cout << endl;
    return 0;
}