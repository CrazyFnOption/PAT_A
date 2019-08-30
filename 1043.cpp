/*
	这道题整体给人的感觉就是特别诡异

    主要是给了一个 先序排列 但是你并不知道其他的排列就让你去确定 一棵树

    但是最后的结果就是 不知道怎么下手，但是题目还给出了另外的条件，平衡二叉树，根据这个去写
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<cstdio>
#include<queue>
#include<map>
#include<cmath>

using namespace std;

int num[1010];
int tree[1010 << 2];
queue<int>q;
bool flag,res;


void buildTree(int l,int r,bool flag) {
    if (l > r || res == 1) return;
    if(l == r) {
        q.push(num[l]);
        return;
    }
    //这里必须对mid赋值，且必须要定义一个局部变量。
    //以后记住用于递归中参数的变量一定不要设置成全局变量
    //将全局变量放到递归参数中，有可能在传入参数的时候就被其他改变


    int mid = r + 1;
    for (int i = l + 1; i <= r; i++) {
        if (flag && num[i] >= num[l]) {
            mid = i;
            break;
        }
        if (!flag && num[i] < num[l]) {
            mid = i;
            break;
        }
    }

    //这个地方我先开始想错了，不应该只比较单独左边和单独右边的数字
    //到后面可以只看 右边的节点的数是不是比当前根节点要大
    for (int i = mid; i <= r; i++) {
        if (flag && num[i] < num[l]) {
            res = 1;
            return;
        }
        if (!flag && num[i] >= num[l]) {
            res = 1;
            return ;
        }
    }
    //如果使用的是全局变量，那么在下一句的时候改变了mid的值，然后进入到右子树的时候会出现问题。
    buildTree(l + 1,mid - 1,flag);
    buildTree(mid,r,flag);
    q.push(num[l]);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n ; i ++) {
        cin >> num[i];
    }

    if (num[1] < num[2]) flag = 0;
    else flag = 1;

    buildTree(1,n,flag);
    if (res == 1) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    cout << q.front();
    q.pop();
    while (!q.empty()) {
        cout << " " << q.front();
        q.pop();
    }
    return 0;
}