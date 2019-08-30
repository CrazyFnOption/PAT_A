/*
	果然这个样子做 一定会超时一个 所以 换另外一种办法
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
#include <iomanip>
using namespace std;

const int maxn = 1e5 + 5;
int n;
double p,r;
int v[maxn];
vector<int>re;

int main()
{
    scanf("%d %lf %lf",&n,&p,&r);
    r = r / 100;
    int x,t;
    for (int i = 0; i < n; i++) {
        scanf("%d",&x);
        if (x == 0) {
            re.push_back(i);
            continue;
        }
        for (int j = 0; j < x; j++) {
            scanf("%d", &t);
            v[t] = i;
        }
    }
    int res = 0;
    double Min = 99999999;
    for (int i = 0; i < re.size(); i++) {
        int cnt = 0;
        int tt = re[i];
        while (tt != 0) {
            tt = v[tt];
            cnt++;
        }
        double x = p * pow(1 + r,cnt);
        if (x < Min) {
            res = 1;
            Min = x;
        }
        else if (x == Min) res ++;
    }
   
    printf("%.4lf %d\n",Min,res);
    
    return 0;
}