/*
	这道题就涉及到了 贪心策略的选取 
    很有意思的一道贪心题目，需要去想清楚贪心的策略
    这里需要注意的是 double 的选项

    要么在能走路径里面去寻找最便宜的，要么就是用便宜的油走最远的距离。
    
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

struct station {
    double price;
    int distance;
    station(double x = 0.0,double y = 0) :price(x),distance(y){}
    bool operator < (const station &s) const {
        return distance < s.distance;
    }
};

int main()
{
	
    double cmax,cdis,per;
    int n;
    vector<station>v;
    cin >> cmax >> cdis >> per >> n;
    double p;
    double dmaxn = per * cmax;
    double x;
    v.push_back(station(0,cdis));
    for (int i = 0; i < n; i++) {
        cin >> p >> x;
        v.push_back(station(p,x));
    }
    sort(v.begin(),v.end());
    if (v[0].distance != 0) {
        cout << "The maximum travel distance = 0.00";
        return 0;
    }
    
    double ans = 0;
    int now = 0;
    double tank = 0;
    while (now < n) {
        double Minp = 0x3f3f3f3f;
        int Minpos = -1;

        for (int i = now + 1; i <= n && v[i].distance - v[now].distance <= dmaxn; i++) {
            if (Minp > v[i].price) {
                Minp = v[i].price;
                Minpos = i;
                if (Minp < v[now].price) break;
            }
        }

        if (Minpos == -1) break;

        double need = (v[Minpos].distance - v[now].distance) / per;
        if (Minp < v[now].price) {
            if (tank > need) {
                tank -= need;
            }
            else {
                ans += (need - tank) * v[now].price;
                tank = 0;
            }
        }
        else {
            ans += (cmax - tank) * v[now].price;
            tank = cmax - need;
        }
        now = Minpos;
    }
    if (now == n) printf("%.2lf",ans);
    else printf("The maximum travel distance = %.2f",double(v[now].distance + dmaxn));
	
    return 0;
}