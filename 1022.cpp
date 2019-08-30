/*
	这道题我认为十分神奇的地方就在于，为什么题目中加了那两行代码就直接判错

    至今想象不出为什么

    这道题虽然题目很长，但是仍然是一道水题，就是将map的运用到实际中了，这道题需要弄清楚的是stringstream的用法。

    我记得 stringstream 的清零 不能直接clear 还有使用 str("");
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
#include <sstream>
#include <set>

using namespace std;

map<string, set<string> > mtitle;
map<string, set<string> > mauthor;
map<string, set<string> > mkey;
map<string, set<string> > mpublish;
map<string, set<string> > myear;

void Find(map<string,set<string> > &m,const string &s) {
    if (m.count(s)) {
        for (set<string>::iterator it = m[s].begin(); it != m[s].end(); ++it)
            printf("%s\n", (*it).c_str());
    }
    else
        printf("Not Found\n");
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    string a, b, c, d, e, x;
    string s;
    
    for (int i = 0; i < N; i++)
    {
        cin >> a ;
        getchar();
        getline(cin, b);
        mtitle[b].insert(a);
        getline(cin, c);
        mauthor[c].insert(a);
        getline(cin, d);
        stringstream ss(d);
        while (ss >> s)
        {
            mkey[s].insert(a);
        }
        getline(cin, e);
        mpublish[e].insert(a);
        getline(cin, x);
        myear[x].insert(a);
    }
    int M;
    cin >> M;
    getchar();
    string tmp;
    
    int num;
    for (int i = 0; i < M; i++)
    {
        
        scanf("%d: ",&num);
        getline(cin, tmp);

        printf("%d: %s\n", num, tmp.c_str());

        if(num == 1) Find(mtitle, tmp);
		else if(num == 2) Find(mauthor, tmp);
		else if(num == 3) Find(mkey, tmp);
		else if(num == 4) Find(mpublish, tmp);
		else Find(myear, tmp);
    }
return 0;
}