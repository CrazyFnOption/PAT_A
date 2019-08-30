/*
	像这样的排序题真的很多，我也不知道为啥 就是很多。
    简单的排序题，只不过需要注意一下自己的读题能力
*/
#include<iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
    using namespace std;
struct Node
{
    char name[11], id[11];
    int grade;
};
int main()
{
    int n;
    scanf("%d", &n);
    vector<Node> ans(n);
    for (int i = 0; i < n; ++i)
        scanf("%s %s %d", ans[i].name, ans[i].id, &ans[i].grade);
    int grade1, grade2;
    scanf("%d %d", &grade1, &grade2);
    
    sort(ans.begin(), ans.end(), [](Node a, Node b) {
        return a.grade > b.grade;
    });
    bool flag = true;
    for (int i = 0; i < n; ++i)
    {
        if (grade1 <= ans[i].grade && ans[i].grade <= grade2)
        {
            printf("%s %s\n", ans[i].name, ans[i].id);
            flag = false;
        }
    }
    if (flag)
        printf("NONE\n");
    return 0;
}