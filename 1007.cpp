/*
	其实这道题也算是一道特别简单的题目，还是动态规划里面最基础的问题，但是总是容易去弄混。

    记得自己当时的问题就在于 这里每一次相加的和，如何保证后面加了负数之后，再次加上一个正数不被影响呢，
    
    下面的注释里面有写，

    因为题目中限制了，如果这道题有多个答案，比如说 前面与后面相加为零，但是后面的那个正数正好作为最后的正确答案的话

    比如 1 2 -3 8

    1 2 -3 正好相加为0  但是题目中要求的 序列 1 2 -3 8 作为最后的结果序列。

    自己当时也在这一块上面纠结。
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



int main()
{
	std::ios::sync_with_stdio(false);
	int m;
    cin >> m;
    int num[m + 5];
    
    for (int i = 0; i < m; i++) {
        cin >> num[i];
    }
    
    int left = 0;
    int tmpleft = 0;
    int right = m - 1;
    int tmp = 0;
    int Max = -1;

    for (int i = 0; i < m; i ++) {
        tmp += num[i];
        //In case that the maximum subsequence is not unique, 
        //output the one with the smallest indices i and j (as shown by the sample case).
        if (tmp < 0) {
            tmp = 0;
            tmpleft = i + 1;
        }
        else if (tmp > Max) {
            Max = tmp;
            right = i;
            left = tmpleft;
        }
    }
    //If all the K numbers are negative, then its maximum sum is defined to be 0, 
    //and you are supposed to output the first and the last numbers of the whole sequence.
    if (Max >= 0) cout << Max << " " << num[left] << " " << num[right] << endl;
    else cout << 0 << " " << num[0] << " " << num[m - 1] << endl;

    return 0;
}