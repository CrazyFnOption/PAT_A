/*
	这一题就是数据结构里面基础解释题了

    不过正好考到了 我的软肋之处，对于二叉树的遍历这一块 我知道怎么遍历过去

    但是我不知道怎么做题目。

    这道题的解释完全就按照下面的详细解释来看。

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

int post[40];
int inorder[40];

struct Bitree {
    int val;
    Bitree *left;
    Bitree *right;
};

Bitree * buitTree(int postleft,int postright,int inleft,int inright) {
    Bitree * root = new Bitree();
    //左右根  所以 后序遍历中最后一个就是根节点
    root->val = post[postright];
    int leftnum,rightnum;
    int i;
    //这里是根据中序遍历的节点 将这个遍历次序分成 左右两个阶段 
    //毕竟 左根右 所以按照下面去进行中序遍历的循环
    for (i = inleft;i <= inright; i++) {
        if (inorder[i] == post[postright]) {
            leftnum = i - inleft;
            rightnum = inright - i;
            break;
        }
    }
    //注意这个地方对于null的处理，不要仅仅只是停留在表面。
    if (leftnum > 0)
        root -> left = buitTree(postleft,postleft + leftnum - 1,inleft,i - 1);
    else root -> left = nullptr;

    if (rightnum > 0)
        root -> right = buitTree(postright - rightnum,postright - 1,i + 1,inright);
    else root -> right = nullptr;

    return root;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) 
        cin >> post[i];
    
    for (int i = 0; i < n; i++) 
        cin >> inorder[i];

    Bitree* root = buitTree(0,n-1,0,n-1);
    queue<Bitree*> q;
    q.push(root);
    cout << root->val;
    while (!q.empty()) {
        Bitree* now = q.front();
        q.pop();
        if (now->left != nullptr) q.push(now->left);
        if (now->right != nullptr) q.push(now->right);
        if (now == root) continue;
        cout << " " << now->val;
    }

    return 0;
}