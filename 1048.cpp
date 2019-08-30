/*
	一道简单题，简单到 我都不敢相信 是这样做

    就是两个指针分开去计数，如果记到了就输出
    不过这道题看了题解，还有其他多种办法可以写出来
    
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

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int num[n + 1];
    for (int i = 0; i < n; i++) 
        scanf("%d",&num[i]);
    sort(num,num+n);

    for (int i = 0; i < n; i++) {
        if(i != 0 && num[i] == num[i - 1]) continue;
        
        for (int j = n - 1; j > i; j--) {
            //cout << i << " " << j << endl;
            if (num[i] + num[j] == k) {
                cout << num[i] << " " << num[j] << endl;
                return 0;
            }
            if (j == i + 1 && num[i] + num[j] > k) {
                cout << "No Solution" << endl;
                return 0;
            }
            if (num[i] + num[j] < k) break;
        }
    }

    cout << "No Solution" << endl;
    return 0;
}