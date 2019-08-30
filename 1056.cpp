/*
	有的时候pat的题目真的一下子很难读懂，

    看了很久的题解才看懂这道题 

    主要就是将n个老鼠，分成m个 然后在每一个小组里面进行排序，进行比较，最后再输出结果

    然后 自己的问题是对于 给出的玩家序列这一个对象错误理解了，第一个玩的而不是按照上面给的第一个进行排序的

    总的来说，这道题还是很有意思的，对于玩家顺序的理解 比如 6 0 8 7 10 
    应该是 第一个玩家是第6个老鼠，而不是第6个玩家第六个玩
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
int order[1005];
int next_order[1005];
int res[1005];

int main()
{
    std::ios::sync_with_stdio(false);
    int np,nc;
    cin >> np >> nc;
    int cnt1 = np;
    int cnt2,group;
    for (int i = 0; i < np; i++) cin >> num[i];
    for (int i = 0; i < np; i++) cin >> order[i];
    int Max,index;
    while (true) {
       cnt2 = 0;
       group = cnt1 / nc;
       if (cnt1 % nc) group ++;
       for (int i = 0; i < cnt1; i = i + nc) {
           Max = -1;
           for (int j = i; j < i + nc && j < cnt1; j++) {
               if (Max < num[order[j]]) {
                   Max = num[order[j]];
                   index = order[j];
               }
           }

           for (int j = i; j < i + nc && j <cnt1; j++) {
               if (order[j] != index) {
                   res[order[j]] = group + 1;
               }
           }
           next_order[cnt2++] = index;
       }
       if(cnt1 <= nc) {
           res[index] = 1;
           break;
       }
       for (int i = 0; i < cnt2 ;i++) 
            order[i] = next_order[i];
        cnt1 = cnt2;
    }
    cout << res[0] ;
    for (int i = 1; i < np; i++) {
        cout << " " << res[i];
    }
    return 0;
}