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
vector<int>pre,in,post;
bool _unique = true;
int n;

void getin(int lpre,int rpre,int lpost,int rpost) {

    if (lpre == rpre) {
        in.push_back(pre[lpre]);
        return;
    }

    //这里相当于是进入到根左右中的左去
    int i = lpre + 1;
    //找到左子树的根
    //这里需要注意的是 对于后序遍历来说 最后一个是根，倒数第二个，要么是左子树的根，要么就是右子树的根
    //而这里判断中序遍历是否唯一的办法 是看一个节点是否有两个子节点，如果只有一个节点，那么可以是左节点，也可以是右节点
    //这里就是把只有一个节点的情况直接全部当成右节点来看
    for (;i <= rpre; i++) {
        if (pre[i] == post[rpost - 1]) break;
    }
    //对于 前序遍历  第一个是根  第二个一定是左子节点的根，所以这里判断其是否相等 如果相等
    //本来一个是左节点，一个是右节点，但是一旦相等，那么就只有一个节点
    //这里的范围选取 前序遍历的左子树，在前序便利中此时的i就是右子树的根，所以需要i-1
    //对于后序遍历 左 右 根 这里就需要去找 前序遍历中的个数，然后依次遍历到这个部分来
    //i - lpre - 1是个数 这个地方的减一是 这样来的
    // i - 1 - (lpre + 1) + 1
    //而后面的减一则是因为前面有一个相等的过程，如果不减去一，则会把右子树的部分算进去
    if (i != lpre + 1) getin(lpre + 1,i - 1,lpost,lpost + (i - lpre - 1) - 1);
    else _unique = false;
    in.push_back(post[rpost]);
    //对应上面，正好这个地方没有减去1
    getin(i,rpre,lpost + (i - lpre - 1),rpost - 1);
}

int main()
{
    cin >> n;
    pre.resize(n);
    post.resize(n);
    for (int i = 0; i < n; i++) cin >> pre[i];
    for (int i = 0; i < n; i++) cin >> post[i];
    getin(0,n-1,0,n-1);
    if (_unique) cout << "Yes" << endl;
    else cout << "No" << endl;
    for (int i = 0; i < n; i++) {
        cout << in[i];
        if (i != n - 1) cout << " ";
    }
    cout << endl;

    return 0;
}
