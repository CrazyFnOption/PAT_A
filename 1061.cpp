/*
	captial letter 是大写字母的意思 真心觉得 pat很多算法题实际上就是英语题

    我光是题目就看了好久。
    总之这道题算是一道简单题，多刷会练习一下手速也是对的。
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
string weekday[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    string sa,sb,sc,sd;
    cin >> sa >> sb >> sc >> sd;
    int a,b,c;
    int cnt;
    int i;
    //记住这个地方 想减的值 比如 'D' - 'A' = 3;
    for (i = 0; i < sa.size() && i < sb.size(); i++) {
        if (sa[i] == sb[i] && sa[i] >= 'A' && sa[i] <= 'G') {
            a = sa[i] - 'A';
            break;
        }
    }
    for (i = i + 1;i < sa.size() && i < sb.size(); i++) {
        if (sa[i] == sb[i] && sa[i] >= 'A' && sa[i] <= 'N') {
            b = sa[i] - 'A' + 10;
            break;
        }
        if (sa[i] == sb[i] && sa[i] >= '0' && sb[i] <= '9') {
            b = sa[i] - '0';
            break;
        }
    }

    for (int i = 0; i < sc.size() && i < sd.size() ;i++) {
        if ((sc[i] == sd[i]) && ((sc[i] >= 'a' && sc[i] <= 'z') ||(sc[i] >= 'A' && sc[i] <= 'Z'))) {
            c = i;
            break;
        }
    }

    cout << weekday[a] ;
    printf(" %02d:%02d",b,c); 
    

    return 0;
}