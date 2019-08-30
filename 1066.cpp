/*
	我觉得关于树专题的题目 我都不是了解的特别清楚 这就是我存在的问题了。
    重点理解 这里需要回顾一下 java大作业里面的 二叉平衡树 以及 红黑树。

    然后发现其实题目中给出的这个图是有问题的。

    不过有时间的话 去回顾一下红黑树 为什么会这样写。

    重点加上重点加上重点。
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

struct avl {
    int val;
    avl * left;
    avl * right;
};

int n;

//个人觉得此处的递归写的特别精彩
int getHight(avl * root) {
    if (root == NULL) return 0;
    return max(getHight(root->left),getHight(root->right)) + 1;
}

avl * rotateRight(avl* root) {
    avl* tmp = root->left;
    root->left = tmp->right;
    tmp->right = root;
    //这里自己出现的错误就是 不能返回root 应该返回的是 旋转之后的节点
    return tmp;
}

avl* rotateLeft(avl * root) {
    avl* tmp = root->right;
    root->right = tmp->left;
    tmp->left = root;
    return tmp;
}


avl* rotateLeftRight(avl* root) {
    root->left = rotateLeft(root->left);
    root = rotateRight(root);
    return root;
}

avl* rotateRightLeft(avl * root) {
    root->right = rotateRight(root->right);
    root = rotateLeft(root);
    return root;
}

avl* insert(avl* root,int x) {
    if (root == NULL) {
        root = new avl();
        root->val = x;
        root->left = root->right = NULL;
        return root;
    }
    //进入左子树，在左子树里面进行判断是否符合条件
    if (x < root->val) {
        root->left = insert(root->left,x);
        int l = getHight(root->left);
        int r = getHight(root->right);

        if (l - r >= 2) {
            //这里来判断是一个什么类型的树
            //树的类型分为LL,RR,LR,RL。
            //这里如果 x小于左子树的值，所以其一定是被安排到了左子树的左子树上，
            //所以就是LL的类型的树，所以使用rotateRight
            //万一不是的话，就是LR类型的树，就要使用rotateLeftRight
            if (x < root->left->val) root = rotateRight(root);
            else root = rotateLeftRight(root);
        }

    }
    //进入右子树 下面去判断树形。
    else {
        root->right = insert(root->right,x);
        int l = getHight(root->left);
        int r = getHight(root->right);
        if (r - l >= 2) {
            if (x < root->right->val) root = rotateRightLeft(root);
            //这里自己差点就写错了，应该是RR的话 像左转
            else root = rotateLeft(root);
        }
    }
    return root;
}


int main()
{
    std::ios::sync_with_stdio(false);
    int x;
    cin >> n;
    avl * root = NULL;
    for (int i = 0 ; i < n; i++) {
        cin >> x;
        root = insert(root,x);
    }
    cout << root->val << endl;
    return 0;
}