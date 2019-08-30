/*
	这又是一个标记的题目，只能说标记大法好
*/
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;
string org, in;
int isVis[256]; //1 = 有输入  > 1 没坏
vector<char> ans;

int main()
{
    cin >> org >> in;

    memset(isVis, 0, sizeof(isVis));

    for (int i = 0; i < in.size(); i++)
    {
        if (in[i] >= 'a' && in[i] <= 'z')
        {
            in[i] = char(in[i] - 'a' + 'A');
        }
        if (!isVis[int(in[i])])
            isVis[int(in[i])] = 1;
    }

    for (int i = 0; i < org.size(); i++)
    {
        if (org[i] >= 'a' && org[i] <= 'z')
        {
            org[i] = char(org[i] - 'a' + 'A');
        }
        if (!isVis[int(org[i])])
        {
            isVis[int(org[i])]++;
            cout << org[i];
        }
    }
    cout << endl;

    return 0;
}