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

int num[25];
struct Tree {
    Tree * left;
    Tree * right;
    int val;
};

int gethight(Tree* root) {
    if (root == NULL) return 0;
    return max(gethight(root->left),gethight(root->right)) + 1;
}

Tree * rotateleft (Tree* root) {
    Tree* tmp = root->right;
    root->right = tmp->left;
    tmp->left = root;
    return tmp;
}

Tree * rotateright(Tree * root) {
    Tree * tmp = root->left;
    root->left = tmp->right;
    tmp->right = root;
    return tmp;
}

Tree * rotateleftright(Tree* root) {
    root->left = rotateleft(root->left);
    root = rotateright(root);
    return root;
}

Tree * rotaterightleft(Tree * root) {
    root->right = rotateright(root->right);
    root = rotateleft(root);
    return root;
}

Tree* insert(Tree* root,int x) {
    if (root == NULL) {
        root = new Tree();
        root->left = root->right = NULL;
        root->val = x;
        return root;
    }
    if (x < root->val) {
        root->left = insert(root->left,x);
        int l = gethight(root->left);
        int r = gethight(root->right);
        if (l - r >= 2) {
            //曾经写过，但是还是忘了，现在就是来判断树形 判断是ll 还是 lr
            //这个地方在补充一下，为啥只判断root->left的大小，因为这个是平衡树，一定只会相差2
            if (x < root->left->val) root = rotateright(root);
            else root = rotateleftright(root);
        }
    }
    else {
        root->right = insert(root->right,x);
        int l = gethight(root->left);
        int r = gethight(root->right);
        if (r - l >= 2) {
            if (x < root->right->val) root = rotaterightleft(root);
            else root = rotateleft(root);
        }
    }
    return root;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int x;
    Tree * root = NULL;
    for (int i = 0; i < n; i++) {
        cin >> x;
        root = insert(root,x);
    }
    queue<Tree*>q;
    q.push(root);
    bool flag = true;
    int i = 0;
    while (!q.empty()) {
        Tree* now = q.front();
        q.pop();
        if (now == NULL && i != n) {
            flag = false;
            continue;
        }
        cout << now->val;
        
        if (i == n - 1) break;
        else cout << " ";
        i++;

        Tree* l = now->left;
        Tree* r = now->right;
        q.push(l);
        q.push(r);
        
    }
    cout << endl;
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}