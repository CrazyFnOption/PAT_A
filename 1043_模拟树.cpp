/*
	这就是第二种思路了，直接按照题目所给的顺序建立一个二叉树
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

struct tree {
    tree *left;
    tree *right;
    int val;
};

vector<int> ori,preorder,minpreoder,postorder;

//这个地方必须要使用引用，因为得保证 后面都是引用自身，在自身上发生改变，共享底层数据。
// 这里是因为只有指针，没有实体，不像以前的建树过程都是有一个数组当做是实体使用
void insert(int tmp,tree * &root) {
    if (root == NULL) {
        root = new tree;
        root->val = tmp;
        root->left = NULL;
        root->right = NULL;
        return;
    }
    //这里真的要自己动手写一遍，真的是没有想到原来这个地方也是存在递归的
    if (tmp >= root->val)  insert(tmp,root->right);
    else insert(tmp,root->left);
}

void preod(tree * root) {
    if (root == NULL) return;
    preorder.push_back(root->val);
    preod(root->left);
    preod(root->right);
}

void minperod(tree *root) {
    if (root == NULL) return;
    minpreoder.push_back(root->val);
    minperod(root->right);
    minperod(root->left);
}

void postod(tree* root) {
    if (root == NULL) return;
    postod(root->left);
    postod(root->right);
    postorder.push_back(root->val);
}

int main()
{
    int n;
    cin >> n;
    int tmp;
    tree *root = NULL;
    bool res = false;
    for (int i = 0;i < n; i++) {
        cin >> tmp;
        insert(tmp,root);
        ori.push_back(tmp);
    }

    if (ori[0] > ori[1]) {
        preod(root);
        if (preorder == ori) res = true;
    }
    else {
        minperod(root);
        if (minpreoder == ori) res = true;
    }

    if (res) {
        postod(root);
        cout << "YES" << endl;
        cout << postorder[0];
        for (int i = 1; i < n; i++) {
            cout << " " << postorder[i];
        }
        cout << endl;
    }
    else cout << "NO" << endl;


    

    return 0;
}