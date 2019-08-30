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

int number[1005];
double value[1005];
int n,k;
double dp[1008];


void zeroonebag(int weight,int value) {
    for (int i = k; i >= weight; i--) {
        dp[i] = max(dp[i],dp[i - weight] + value);
    }
}

void completebag(int weight,int value) {
    for (int i = weight; i <= k; i++) {
        dp[i] = max(dp[i],dp[i - weight] + value);
    }
}

void mutiplybag(int w,int v,int number) {
    if (k <= w * number) {
        completebag(w,v);
        return ;
    }
    int k = 1;
    while (k <= number) {
        zeroonebag(k * w, k * v);
        number = number - k;
        k = k * 2;
    }
    zeroonebag(number * w, number * v);
}

int main()
{
	scanf("%d %d",&n,&k);
    for (int i = 1; i <= n; i++) {
        scanf("%d",&number[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%lf",&value[i]);
        value[i] = value[i] / (double) number[i];
    }
    for (int i = 1; i <= n; i++)
        mutiplybag(1,value[i],number[i]);
    
    printf("%.2lf",dp[k]);
    return 0;
}