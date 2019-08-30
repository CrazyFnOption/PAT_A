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

int n;
int num[100005];



int main()
{
    
    scanf("%d",&n);
    int pos;
    int x;
    for (int i = 0; i < n; i++) {
        scanf("%d",&x);
        num[x] = i;
        if (x == 0) pos = i;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (num[i] != i) {
            while (num[0] != 0) {
                //这一步就相当于并查集里面的路径压缩，
                //只不过是一个简略版的路径压缩
                swap(num[0],num[num[0]]);
                cnt++;
            }
            if (num[i] != i) {
                cnt++;
                swap(num[0],num[i]);
            }
        }
    }
    
    printf("%d",cnt);
    return 0;
}