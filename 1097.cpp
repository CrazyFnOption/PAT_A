/*
    这里我总是习惯性的去根据指针去一步一步去对，但是实际上当我给每一个序列设定好顺序之后，就不需要去太关心指针的next的值

    意思就是我不需要太去考虑一个指针的指向值，因为下一个序列的元素 就是我上一个序列的地址

    这里直接利用了一个标记来计算的  算是一道简单的题目了，需要弄清楚这一类的问题

    下回遇到这一系列的题目的话 都需要注意的是 题目的中文意思了。
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
const int MAXN = 1e6;
const int MAXM = 1e4 + 10;
struct node
{
    int key, addrnext;
} t[MAXN];
vector<int> res, dup;
int book[MAXM];
int main()
{
    int first, n, x;
    scanf("%d%d", &first, &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &x);
        scanf("%d%d", &t[x].key, &t[x].addrnext);
    }
    while (first != -1)
    {
        if (book[abs(t[first].key)] == 0)
        {
            book[abs(t[first].key)] = 1;
            res.push_back(first);
        }
        else
            dup.push_back(first);
        first = t[first].addrnext;
    }
    for (int i = 0; i < res.size(); ++i)
        if (i == res.size() - 1)
            printf("%05d %d -1\n", res[i], t[res[i]].key);
        else
            printf("%05d %d %05d\n", res[i], t[res[i]].key, res[i + 1]);
    for (int i = 0; i < dup.size(); ++i)
        if (i == dup.size() - 1)
            printf("%05d %d -1\n", dup[i], t[dup[i]].key);
        else
            printf("%05d %d %05d\n", dup[i], t[dup[i]].key, dup[i + 1]);
    return 0;
}
