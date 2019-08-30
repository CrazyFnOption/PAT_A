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

struct node{
    node * l;
    node * r;
    int val;
};
int num[35];

node* insert(node *root,int x) {
    if (root == NULL) {
        root = new node();
        root->l = root->r = NULL;
        root->val = x;
        return root;
    }
    if (abs(root->val) > abs(x)) root->l = insert(root->l,x);
    else root->r = insert(root->r,x);
    return root;
}

bool judge(node * root) {
    if (root == NULL) return true;
    if (root->val < 0) {
        if (root->l != NULL && root->l->val < 0) return false;
        if (root->r != NULL && root->r->val < 0) return false;
    }
    return judge(root->l) && judge(root->r);
}

int getnum(node * root) {
    if (root == NULL) return 0;
    int l = getnum(root->l);
    int r = getnum(root->r);
    if (root->val < 0) return max(l,r);
    return max(l,r) + 1;
}

bool judge2(node * root) {
    if (root == NULL) return true;
    int l = getnum(root->l);
    int r = getnum(root->r);
    if (l != r) return false;
    return judge2(root->l) && judge2(root->r); 
}

int main()
{
    int n;
    cin >> n;
    
    while (n--) {
        node *root = NULL;
        int t,x;
        cin >> t;
        for (int i = 0; i < t; i++) {
            cin >> num[i];
            root = (insert(root,num[i]));
        }
        if (num[0] > 0 && judge(root) && judge2(root)) cout << "Yes" << endl;
        else cout << "No" << endl;
        
    }

    return 0;
} 