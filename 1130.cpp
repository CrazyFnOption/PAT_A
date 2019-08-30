/*
	好题 这里是把输出中序遍历进行了一个 变换 这个变换还蛮厉害了 

    不过以后如果要控制字符串格式的话 记住这样写有一定的好处
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

struct Node {
    string s;
    int l;
    int r;
}node[25];
int root;
bool vis[25];
string res;
//关于中序遍历输出的两种方式
//按照相应的顺序来， 加括号 递归  加括号  输出  加括号 递归 加括号
// 以后像这样要控制格式的  还是自己在dfs里面进行控制格式吧

string dfs(int x) {
    if (x == -1) return "";
    if (node[x].l != -1 || node[x].r != -1) {
        node[x].s = dfs(node[x].l) + node[x].s + dfs(node[x].r);
        if (x != root) node[x].s = "(" + node[x].s + ")";
    }
    return node[x].s;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> node[i].s >> node[i].l >> node[i].r;
        if (node[i].l != -1) vis[node[i].l] = true;
        if (node[i].r != -1) vis[node[i].r] = true;
    }
    root = 0;
    for (int i = 1; i <= n ; i++) {
        if (!vis[i]) {
            root = i;
            break;
        }
    }
    cout << dfs(root) << endl;


    return 0;
}