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

const int maxn = 1015;
int num[maxn];
int n,m;

void dfs(int x,vector<int>v) {
    if (x <= n) v.push_back(num[x]);
    if (x > n) return ;
    if (x * 2 + 1 > n && x * 2 > n) {
        
        for (int i = 0; i < v.size(); i++) {
            cout << v[i];
            if (i != v.size() - 1) cout << " ";
        }
        cout << endl;
    }
    
    dfs(x * 2 + 1, v);
    dfs(x * 2,v);
    
    
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    
        bool f1 = true,f2 = true;
        for (int i = 1; i <= n; i++) {
            cin >> num[i];
        }
        //f1 小顶堆 f2 大顶堆
        if (num[1] > num[2]) f1 = false;
        else f2 = false;
        for (int i = 2; i <= n; i++) {
            if (f1 && num[i / 2] > num[i]) {
                f1 = false;
                break;
            }
            if (f2 && num[i / 2] < num[i]) {
                f2 = false;
                break;
            }
        }
        vector<int>v;
        
        dfs(1,v);
        if (f1) cout << "Min Heap" << endl;
        else if (f2) cout << "Max Heap" << endl;
        else cout << "Not Heap" << endl;
    return 0;
}