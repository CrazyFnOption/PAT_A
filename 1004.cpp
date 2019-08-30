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

int n,m;
vector<int> kids[105];
int maxlever = 0;
int nums[105];

void dfs(int root,int depth) {
    if (kids[root].size() == 0) {
        maxlever = max(depth,maxlever);
        nums[depth]++;
        return;
    }
    for (int i = 0; i < kids[root].size() ; i++) {
        dfs(kids[root][i],depth + 1);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    int fa,num;
    int tmp;
    memset(nums,0,sizeof nums);
    for (int i = 0; i < m; i++) {
        cin >> fa >> num;
        for (int i = 0 ; i < num; i ++) {
            cin >> tmp;
            kids[fa].push_back(tmp);
        }
    }

    dfs(1,0);
    cout << nums[0] ;
    
    for (int i = 1; i <= maxlever; i++ ) {
        cout << " " << nums[i];
    }
    cout << endl;
    return 0;
}