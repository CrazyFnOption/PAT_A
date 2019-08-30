/*
	一道简简单单的模拟题 考验手速的时候到了
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

const int maxn = 1e5 + 5;
int rank_[maxn];
bool vis[maxn];

bool isprime(int x) {
    for (int i = 2;i <= sqrt(x); i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main()
{
    int n,k,x;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) {
        scanf("%d",&x);
        rank_[x] = i;
    }
    scanf("%d",&k);
    for (int i = 0; i < k; i++) {
        scanf("%d",&x);
        if (rank_[x] == 0) {
            printf("%04d: Are you kidding?\n", x);
            continue;
        }
        if (vis[x]) {
            printf("%04d: Checked\n", x);
            continue;
        }
        if (!vis[x] && rank_[x] == 1) {
            vis[x] = true;
            printf("%04d: Mystery Award\n",x);
            continue;
        }
        if (!vis[x] && isprime(rank_[x])) {
            vis[x] = true;
            printf("%04d: Minion\n", x);
            continue;
        }
        vis[x] = true;
        printf("%04d: Chocolate\n", x);
    
    }
    return 0;
}