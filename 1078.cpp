/*
	这道题考的是哈希表中的二次探测法，我记得还有一个线性探测法

    这真的是涨姿势的一道题，

    不过需要注意的是 如果以后遇到素数相关的题目，一定就要去联想 1 不是质数，1 这里处于特殊情况。
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

bool isprime(int x) {
    for (int i = 2; i <= sqrt(x);i++) {
        if (x % i == 0) return false;
    }
    return true;
}
int n, m,t,k;
int num[10005];
bool vis[10005];
int _hash(int x) {
    return x % n;
}


int main()
{
    
    scanf("%d %d",&n,&m);
    if (1 == n) n = 2;
    if (!isprime(n)) {
        for (int i = n + 1;;i++) {
            if (isprime(i)) {
                n = i;
                break;
            }
        }
    }
    

    for (int i = 0; i < m; i++) {
        if (i != 0) printf(" ");
        scanf("%d",&t);
        k = _hash(t);
        if (!vis[k]) {
            vis[k] = true;
            printf("%d",k);
        }
        else {
            int j;
            int res;
            for (j = 1; j < n; j++) {
                res = (t + j * j) % n;
                if (!vis[res]) {
                    vis[res] = true;
                    printf("%d",res);
                    break;
                }
            }
            if (j == n) printf("-");
        }
    }





    return 0;
}