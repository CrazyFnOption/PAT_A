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

struct person {
    int ct,et;
    person(){}
    person(int a, int b): ct(a),et(b){}
    bool operator < (const person & p) const {
        return ct < p.ct;
    }
};

int n,k;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    vector<person> v;
    scanf("%d %d",&n,&k);
    int h,m,s,t;
    for (int i = 0;i < n; i++) {
        scanf("%d:%d:%d %d",&h,&m,&s,&t);
        if (t > 60) t = 60;
        int tmp = h * 3600 + m * 60 + s;
        if (tmp > 17 * 3600) continue;
        v.push_back(person(tmp,t));
    }

    //这里如果按照我一般的做法就基本上是存储人上去了，，因为只有人进人出才符合模拟的特性
    //但是意外的看了一下大佬写的代码，完全只用记录相应的时间就可以了
    //这道题与之前做的不一样的是，我可以在前面直接进行一个顺序排列，根据人的优先来进出队列
    //而且此处并不涉及到站在队列中等待的过程，所以算是一道简单题。
    //于是这里就只需要记住他们来的时间就可以了。
    sort(v.begin(),v.end());
    int Min,index;
    double total = 0;
    vector<int> window(k,8 * 3600);
    for (int i = 0;i < v.size(); i++) {
        Min = window[0];
        index = 0;
        for (int j = 1; j < k; j++) {
            if (Min > window[j]) {
                Min = window[j];
                index = j;
            }
        }
        if (Min <= v[i].ct) window[index] = v[i].ct + v[i].et * 60;
        else {
            total += Min - v[i].ct;
            window[index] += v[i].et * 60;
        }
    }
    printf("%.1lf\n",total / v.size() / 60);

    return 0;
}