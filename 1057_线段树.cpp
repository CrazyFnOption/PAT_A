/*
    线段树还是跟树状数组一样的做法，直接将线段树的节点当成子节点数的和
    但是跟以前做的题目不一样的是，这道题计数不是计算相应的值，而是在值的位置加1，相当于有这个数

    所以巧妙点就在这里了
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
#include <stack>

using namespace std;

const int maxn = 1e5 + 10;
int tree[maxn << 2];

//写这个线段树的时候有点搞忘了，线段树的板子里面的参数，主要是要弄清楚根节点与左右两个参数的关系
void update(int l, int r,int k,int pos,int val) {
    tree[k] += val;
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (mid >= pos)
        update(l,mid,k << 1,pos,val);
    else update(mid + 1,r,k << 1 | 1,pos,val);
}

//线段是前面还是挺轻松的，直到下面这里的单点查询出乎意料，
//下面不同的地方是 以前用mid来控制左右，现在直接用tree本身的值来控制左右
//这样的好处
void query(int l,int r,int k,int pos) {
    if (l == r) {
        cout << l << endl;
        return;
    }
    int mid = (l + r) >> 1;
    if (tree[k << 1] >= pos) 
        query(l,mid,k << 1,pos);
    //如果是在右子树的话，那么就需要去考虑 更换初始点 以前是以起点，但是现在就是以tree[k << 1]
    else query(mid + 1,r,k << 1 | 1,pos - tree[k << 1]);
}


int n;
string s;
stack<int> ss;

int main()
{
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s == "Pop") {
            if (ss.empty()) {
                cout << "Invalid" << endl;
                continue;
            }
            tmp = ss.top();
            ss.pop();
            update(1,maxn,1,tmp,-1);
            cout << tmp << endl;

        }
        else if (s == "Push") {
            cin >> tmp;
            ss.push(tmp);
            update(1,maxn,1,tmp,1);
        }
        else {
            if (ss.empty()) {
                cout << "Invalid" << endl;
                continue;
            }
            int x = ss.size();
            query(1,maxn,1,(x + 1) / 2);
        }
    }
    return 0;
}
