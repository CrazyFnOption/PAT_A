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

int num[10005];

int upper_bound(int left,int right,int val) {
    while (left <= right) {
        int mid = (left + right) >> 1;
        if (num[mid] == val) return mid;
        if (num[mid] > val) right = mid;
        else left = mid + 1;
    }
    return -1;
}
int n,m;
vector<int>res,tmp;

bool cmp(const vector<int> &a,const vector<int> &b) {
    int Min = min(a.size(),b.size());
    for (int i = 0; i < Min; i++) {
        if (a[i] == b[i]) continue;
        return a[i] < b[i];
    }
    return a.size() < b.size();
}
int sum;
void dfs(int x) {
    if (sum > m) return ;
    if (sum == m) {
        cout << "yes" << endl;
        res = min(res,tmp,cmp);
        return;
    }
    for (int i = x; i < n; i++) {
        sum += num[x];
        tmp.push_back(num[x]);
        dfs(x + 1);
        sum -= num[x];
        tmp.pop_back();
        dfs(x + 1);
    }
    return ;
}

int main()
{
    
    scanf("%d %d",&n,&m);
    for (int i = 0; i < n; i++) {
        scanf("%d",&num[i]);
    }
    sort(num,num + n);
    sum = 0;
    dfs(0);
    sort(res.begin(),res.end());
    if (res.size() == 0) {
        printf("No Solution");
        return 0;
    }
    printf("%d",res[0]);
    for (int i = 1; i < res.size(); i++)   
        printf(" %d",res[i]);
    
    return 0;
}