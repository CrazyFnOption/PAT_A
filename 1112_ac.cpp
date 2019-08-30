#include <iostream>
#include <map>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
bool hashtable[500];
bool isprintf[500];
string s;
int main()
{
    int k;
    scanf("%d", &k);
    getchar();
    getline(cin, s);
    memset(hashtable, true, sizeof(hashtable));
    int i = 0, j = 1;
    while (i < s.length())
    {
        //这个地方直接两个指针就可以了
        while (j < s.length() && s[j] == s[i])
            j++;
        if ((j - i) % k != 0)
            hashtable[s[i]] = false; //整倍数
        i = j, j++;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (hashtable[s[i]] && isprintf[s[i]] == false)
            printf("%c", s[i]), isprintf[s[i]] = true;
    }
    printf("\n");
    i = 0;
    while (i < s.length())
    {
        printf("%c", s[i]);
        if (hashtable[s[i]] == true)
            i += k;
        else
            i++;
    }
    return 0;
}