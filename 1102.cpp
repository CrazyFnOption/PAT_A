/*
	这道题需要注意一下自己的思路
    前面也许做过相类似的题目，但是这道题不一样的地方就在于他不是二叉平衡树

    所以其的中序遍历是不能够直接作为其递增的序列 就像前面有一道题构造平衡二叉树的题目

    所以这个地方就需要自己去寻找根节点 ，就是标记所有的子节点，没有被标记的就是根节点

    这里需要注意的是英文的读题问题，这还可以共同使用一个and的问题
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
vector<int>in,lev;

struct Node {
    int left;
    int right;
    int val;
    int pos;
}node[15];

bool vis[15];

int tot = 0;
void buildTree(int x) {
    if (x == -1) return ;
    buildTree(node[x].right);
    in.push_back(x);
    buildTree(node[x].left);
}

void level(int x) {
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        lev.push_back(now);
        
        int l = node[now].left;
        int r = node[now].right;
        if (r != -1) q.push(r);
        if (l != -1) q.push(l);
    }
}

int main()
{
    scanf("%d",&n);
    getchar();
    
    char a,b;
    for (int i = 0; i < n; i++) {
        scanf("%c %c",&a,&b);
        if (a == '-') node[i].left = -1;
        else node[i].left = a - '0';
        if (b == '-') node[i].right = -1;
        else node[i].right = b - '0';
        getchar();
        if (node[i].left != -1) vis[node[i].left] = true;
        if (node[i].right != -1) vis[node[i].right] = true;
    }
    int root;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            root = i;
            break;
        }
    }
    buildTree(root);
    level(root);

    for (int i = 0; i < n; i++) {
        cout << lev[i];
        if (i != n - 1) cout << " ";
    }

    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << in[i];
        if (i != n - 1) cout << " ";
    }
    

    return 0;
}