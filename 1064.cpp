/*
	这里涉及到了完全二叉树的性质，其实自己一直以来都知道，但是没有很熟悉，就是对二叉树没有感觉

    二叉树就是 一个一个的按照序列 直接满掉的二叉树，编号直接就是按照0 到 n 工整的排下去，是由满二叉树引申出来的

    但是满二叉树只要保证 除了叶子节点，每个节点都有两个子节点。

    所以二叉树的建树过程，就可以直接用像线段树一样建树 i 节点的左子树 i << 1 右子树就是 i << 1 | 1

    完全二叉平衡树的中序遍历，就直接是 给出数组的递增序列

    左 -> 根 -> 右。

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

int num[1005];
int _index = 1;
int tree[1005];
int n;
void build (int x) {
    if (x > n) return;
    build(x << 1);
    // 这个地方出错了，原因是没有理解这层递归，分别左子树，右子树进行赋值。
    tree[x] = num[_index++];
    build(x << 1 | 1);
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }
    sort(num + 1,num + 1 + n);
    build(1);

    cout << tree[1];
    for (int i = 2; i <= n; i++) 
        cout << " " << tree[i];
    return 0;
}