/*
	第一次遇到这种需要用到哈希表的题目，

    将 string 映射到 int 有很多种方法
    要么使用map 要么就是下面所提到的哈希表了


    不过这也提醒我了，当以后遇到map映射出现问题的时候，可以自己来映射；
    
    由于题目给出了名字只有四个字符，前三个字符是A—Z 最后一个字符是数字0-9
    26∗26∗26∗10=175761

    所以映射函数就直接为 
    return (s[0]-'A') * 26 * 26 * 10 + (s[1]-'A') * 26 * 10 + (s[2]-'A') * 10 + s[3];

    这个样子就叫离散化。


*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stdio.h>
using namespace std;
inline int deal(char *s);
vector<int> student[180000];
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	int idex, amountpeople;
	char str[10];
	for (int i = 0; i < k; ++i) {
		scanf("%d %d", &idex, &amountpeople);
		for (int i = 0; i < amountpeople; ++i) {
			scanf("%s", str);
			student[deal(str)].push_back(idex);
		}
	}
	for (int i = 0; i < n; ++i) {
		scanf("%s", str);
		int idex = deal(str);
		sort(student[idex].begin(), student[idex].end());
		printf("%s %d", str, student[idex].size());
		for (int i = 0; i < student[idex].size();++i) {
			printf(" %d", student[idex][i]);
		}
		putchar('\n');
	}
	return 0;
}
int deal(char* s) {
	return (s[0]-'A') * 26 * 26 * 10 + (s[1]-'A') * 26 * 10 + (s[2]-'A') * 10 + s[3];
}