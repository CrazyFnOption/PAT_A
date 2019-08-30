#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<cstdio>
#include<queue>
#include<map>
#include<cmath>
#include<iomanip>

using namespace std;



double num[1005],num2[1005];


int main()
{
	std::ios::sync_with_stdio(false);
	int a,b,x;
    cin >> a;
    double tmp;
    memset(num,0,sizeof num);
    memset(num2,0,sizeof num2);
    for (int i = 0; i < a; i++) {
        cin >> x >> tmp;
        num[x] += tmp;
    }
    cin >> b;
    for (int i = 0; i < b; i++) {
        cin >> x >> tmp;
        num2[x] += tmp;
    }
    int cnt = 0;
    for (int i = 0; i < 1002; i++) {
        if (num[i] == 0 && num2[i] == 0) continue;
        num[i] += num2[i];
        if (num[i] == 0) continue;
        cnt ++;
    }
    printf("%d",cnt);
    for (int i = 1002; i >= 0; i--) {
        if (num[i] != 0) {
            
            
            printf(" %d %.1f",i,num[i]);
        }
    }
    printf("\n");

    return 0;
}