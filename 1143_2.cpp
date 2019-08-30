/*
	这里有两种方法去 求lca 一种值最正常的办法 另外一种就是 利用二叉搜树的顺序去求解

    两个最近的祖先  一定是一个在两者大小排序中间
    后面有时间补一下正常的LCA该怎么去写
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

const int maxn = 10100;
int pre[maxn];
int in[maxn];
//这里的bug找了好长时间  
map<int,bool>vis;

struct node{
    node * l;
    node *r;
    int val;
};


node * buildTree(int lpre,int rpre,int lin,int rin) {
    if (lin > rin || lpre > rpre) return NULL;
    node *root = new node();
    root->val = pre[lpre];
    root->l = root->r = NULL;
    int i = lin;
    while (pre[lpre] != in[i] && i <= rin) i++;
    root->l = buildTree(lpre + 1,lpre + i - lin,lin,i - 1);
    //因为这里i就代表根的位置，这位置不能轻易丢失
    root->r = buildTree(lpre + i - lin + 1,rpre,i + 1,rin);
    return root;
}

void dfs(int u,int v,node *root) {
    if (root == NULL) return;
    if (root->val == u) {
        printf("%d is an ancestor of %d.\n",u,v);
        return;
    }
    if (root->val == v) {
        printf("%d is an ancestor of %d.\n",v,u);
        return ;
    }
    if (((root->val > u && root->val < v)) || (root->val < u && root->val > v)) {
        printf("LCA of %d and %d is %d.\n",u,v,root->val);
        return ;
    }
    if (root->val > u && root->val > v) dfs(u,v,root->l);
    else dfs(u,v,root->r);
}


int main()
{
    
    int n,m;
    scanf("%d %d",&m,&n);
    for (int i = 1; i <= n; i++) {
        scanf("%d",&pre[i]);
        in[i] = pre[i];
        vis[in[i]] = true;
    }
    sort(in + 1,in + n + 1);
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
        int x;
        //正好这里可以直接利用前序遍历这样写
        dfs(a,b,root);



    }
    return 0;
}