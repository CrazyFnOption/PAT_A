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
const int maxn = 1e5 + 10;
int pre[maxn],in[maxn];
map<int,bool> vis;
struct node {
    node *l;
    node *r;
    int val;
};

node * buildTree(int lin,int rin,int lpre,int rpre) {
    node * root = new node();
    root->val = pre[lpre];
    int i = lin;
    while (i <= rin && in[i] != pre[lpre]) i++;
    if (i > lin) root->l = buildTree(lin,i - 1,lpre + 1,lpre + i - lin);
    if (i < rin) root->r = buildTree(i + 1,rin,lpre + i - lin + 1,rpre);
    return root;
}

node * dfs(node * root,int a,int b) {
    if (root == NULL) return NULL;
    if (root->val == a || root->val == b) return root;
    node *l = dfs(root->l,a,b);
    node *r = dfs(root->r,a,b);
    if (l != NULL && r != NULL) return root;
    if (l != NULL) return l;
    return r;
    
}

int main()
{
    
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        cin >> in[i];
        vis[in[i]] = true;
    }
    for (int i = 1; i <= n; i++) cin >> pre[i];

    node * root = buildTree(1,n,1,n);

    int a,b;
    for (int i = 0; i < m; i++) {
        scanf("%d %d",&a,&b);

        if (!vis[a] || !vis[b]) {
            if (!vis[a] && !vis[b]) {
                printf("ERROR: %d and %d are not found.\n",a,b);
            }
            else if (!vis[a]) {
                printf("ERROR: %d is not found.\n",a);
            }
            else printf("ERROR: %d is not found.\n",b);
            continue;
        }
        
        node* s = dfs(root,a,b);
        if (s->val == a || s->val == b) {
            if (root->val == a) printf("%d is an ancestor of %d.\n",a,b);
            else printf("%d is an ancestor of %d.\n",b,a);
        }
        else printf("LCA of %d and %d is %d.\n",a,b,s->val);

    }
    return 0;
}