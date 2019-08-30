/*
	直接简单哈希就可以了啊  或者map映射，感觉被这道题侮辱了智商。
*/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
string s1, s2;
int hashtable[256];
int main()
{
    getline(cin, s1);
    getline(cin, s2);
    int mis = 0;
    for (int i = 0; i < s1.length(); i++)
        hashtable[s1[i]]++;
    for (int i = 0; i < s2.length(); i++)
    {
        if (hashtable[s2[i]])
            hashtable[s2[i]]--;
        else
            mis++;
    }
    if (mis == 0)
    {
        printf("Yes %d", s1.length() - s2.length());
    }
    else
        printf("No %d", mis);
    return 0;
}