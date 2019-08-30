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


vector<int> v, inord,post;
int n, a;
void postorder(int root,int l,int r) {
    if (l > r) return;
    int mid = l;

    //这里有一个问题，这里的r 必须小于等于
    for (int i = l ; i <= r; i++) {
        if (v[root] == inord[i]) {
            mid = i ;
            break;
        }
    }

    //while (v[root] != inord[mid]) ++mid;
    // root + 1 是在前序遍历里面根的位置
    postorder(root + 1,l,mid - 1);
    //这里本来的想法是直接通过根左右来计算，但是右子树不能这么计算
    //之前的想法是通过中序遍历中的 左根右 来计算左边与右边的距离
    //但是实际上这里利用的是根左右 所以 应该通过前序遍历中的 左根的距离
    postorder(mid + 1 - l + root,mid + 1,r);
    if (root == 0) cout << v[root] << endl;
    else cout << v[root] << " ";
    //总之在哪里利用数组比较，就遵守哪里数组的关系
}

int main()
{
    
    
    cin >> n;
    int cnt = 0;
    //前序遍历和中序遍历
    
    stack<int>ss;
    
    string s;
    while (true) {
        cin >> s;
        if (s == "Push") {
            cin >> a;
            v.push_back(a);
            ss.push(a);
        }
        else {
            inord.push_back(ss.top());
            ss.pop();
            cnt ++;
            if (cnt == n) break;
        }
    }

    postorder(0,0,n-1);


    return 0;
}