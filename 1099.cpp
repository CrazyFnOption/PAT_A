/*
    关于树的题目 真的需要多练练，有一定的技巧 等技巧熟练了 基本上就会做了。
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

int n;

struct Node {
    int left;
    int right;
    int val;
    int pos;
}node[105];

int num[105];
int tot = 0;
void buildTree(int x) {
    if (x == -1) return;
    buildTree(node[x].left);
    node[x].val = num[tot++];
    buildTree(node[x].right);
}

void level (int x) {
    queue<int>q;
    q.push(x);
    int i = 0;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        cout << node[now].val;
        if (i != n - 1) cout << " ";
        i++;
        int l = node[now].left;
        int r = node[now].right;
        if (l != -1) q.push(l);
        if (r != -1) q.push(r);
    }
}



int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> node[i].left >> node[i].right;
        node[i].pos = i;
    }

    for (int i = 0; i < n; i++) cin >> num[i];

    sort(num,num + n);
    buildTree(0);
    level(0);
    return 0;
}