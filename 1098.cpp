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

int num[105];
int copy_[105];
int temp[105];
int n;
bool check(int a[]) {
    for (int i = 1; i <= n; i++) {
        if (a[i] != temp[i]) return false;
    }
    return true;
}

void show (int a[]) {
    cout << a[1];
    for (int i = 2; i <= n; i++) {
        cout << " " << a[i];
    }
}

bool ins() {
    bool flag = false;
    for (int i = 2; i <= n; i++) {
        if (i != 2 && check(copy_)) {
            flag = true;
        }
        for (int j = i - 1; j >= 1; j--) {
            if (copy_[j] > copy_[j + 1]) {
                swap(copy_[j],copy_[j + 1]);
            }
            else break;
        }
        if (flag) break;
    }
    if (flag) return true;
    else return false;

}

void adjust(int root,int len) {

    //这个地方的len时间让我自闭  记住堆排序的时候这个地方的长度需要去更改，因为要注重的是每一个长度
    int child = 2 * root ;
    while (child < len) {
        if (child + 1 < len && num[child] < num[child + 1]) child ++;
        if (num[root] < num[child]) {
            swap(num[child],num[root]);
            root = child;
            child = 2 * child ;
        }
        else return;
    }
    return;
}

void heap() {
    bool flag = false;
    //第一个循环 专门去构造大顶堆，或者小顶堆
    for (int i = n / 2; i >= 1; i--) adjust(i,n);
    //第二个循环才是逐渐去慢慢输出顺序的地方
    for (int i = n; i > 1; i --) {
        if (i != n && check(num)) flag = true;
        swap(num[1],num[i]);
        //这里需不需要减1 是根据上面的adjust里面对于上限值的处理 如果是大于等于就需要减去1 如果仅仅只是小于，那么就不需要减去1
        adjust(1,i);
        if (flag) return;
    }
    
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        copy_[i] = num[i];
    }
    for (int i = 1; i <= n; i++) cin >> temp[i];

    if (ins()) {
        cout << "Insertion Sort" << endl;
        show(copy_);
    }

    else {
        cout << "Heap Sort" << endl;
        heap();
        show(num);
    }
    return 0;
}