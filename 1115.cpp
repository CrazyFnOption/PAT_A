/*
	看清楚二叉树那一块的定义 题目在这个定义这里下了陷阱，真实恶心。
    简单题

    一发AC  
    不过看了下 题解 发现其实dfs的过程可以直接写在建树里面
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
    Node * left;
    Node * right;
    int val;
};

Node * buildTree(Node * root,int x) {
    if (root == NULL) {
        root = new Node();
        root->left = root->right = NULL;
        root->val = x;
        return root;
    }
    if (x <= root->val) root->left = buildTree(root->left,x);
    else root->right = buildTree(root->right,x);
    return root;
}

int num[1005];
int Max = -1;

void dfs(Node* root,int depth) {
    if (root == NULL) {
        Max = max(Max,depth);
        return;
    }
    num[depth] ++;
    dfs(root->left,depth + 1);
    dfs(root->right,depth + 1);
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    Node* root = NULL;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        root = buildTree(root,x);
    }
    
    dfs(root,0);

    

    cout << num[Max - 1] << " + " << num[Max - 2] << " = " << num[Max - 1] + num[Max - 2] << endl;
    
    return 0;
}