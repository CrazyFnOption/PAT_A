/*
	这道题不知道为什么 总是有一个样例过不了。

    考虑了所有的情况，但还是有一个三分的样例过不了，所以我也不知道该怎么办了

    经过3个小时的顽强拼搏，总算是将这道题给过了，不过这道题很扯 题目数据很扯

    这个样例出了问题
    3 50 
    a b 20
    c d 30
    a c 1

    如果数据不水的话 我应该会很早就发现这个问题。
    
*/
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<set>

using namespace std;

int n,k,tmp;
string s1,s2;
map<string,int>m;
set<string>s[1010];
set<string> :: iterator it1,it2,it,ip1,ip2;
vector<pair<string,int> >res;

bool cmp (const pair<string,int>& p1,const pair<string,int>& p2) {
    return p1.first < p2.first;
}
int main()
{
    int tot = 0;
    bool flag ;
    res.clear();
    cin >> n >> k;
    m.clear();
    for (int i = 0; i < n; i++) {
        s[i].clear();
    }
    for (int i = 0; i < n; i++) {
        flag = false;
        cin >> s1 >> s2 >> tmp;
        m[s1] += tmp;
        m[s2] += tmp;
        if (tot == 0) {
            s[tot].insert(s1);
            s[tot].insert(s2);
            tot++;
            continue;
        }
        for (int j = 0; j < tot; j++) {
            it1 = s[j].find(s1);
            it2 = s[j].find(s2);
            if (it1 == s[j].end() && it2 == s[j].end()) continue;
            flag = true;
            
            if (it1 != s[j].end()) {
                
                for (int u = j + 1; u < tot; u++) {
                    if (s[u].empty()) continue;
                    ip2 = s[u].find(s2);
                    if (ip2 == s[u].end()) continue;
                    if(s[j].size() < s[u].size()) {
                        s[u].insert(s[j].begin(),s[j].end());
                        s[j].clear();
                    }
                    else {
                        s[j].insert(s[u].begin(),s[u].end());
                        s[u].clear();
                    }
                }
                s[j].insert(s2);
            }

            else {
                
                for (int u = j + 1; u < tot; u++) {
                    if (s[u].empty()) continue;
                    ip1 = s[u].find(s1);
                    if (ip1 == s[u].end()) continue;
                    if(s[j].size() < s[u].size()) {
                        s[u].insert(s[j].begin(),s[j].end());
                        s[j].clear();
                    }
                    else {
                        s[j].insert(s[u].begin(),s[u].end());
                        s[u].clear();
                    }
                }
                s[j].insert(s1);

            }
        }
        if (!flag) {
            s[tot].insert(s1);
            s[tot].insert(s2);
            tot++;
        }
    }

    int ans,Max;
    string n= "";
    for (int i = 0; i < tot; i++) {
        ans = 0;
        Max = -0x3f3f3f3f;
        if (s[i].size() < 3) continue;
        for (it = s[i].begin();it != s[i].end(); it++) {
            tmp = m[*it];
            ans += tmp;
            if (Max <= tmp) {
                Max = tmp;
                n = *it;
            }
        }
        ans = ans / 2;
        if (ans > k && s[i].size() >= 3) {
            res.push_back(make_pair(n,s[i].size()));
        }
    }
    tmp = res.size();
    if (tmp == 0) {
        cout << "0" << endl;;
        return 0;
    }
    sort(res.begin(),res.end(),cmp);
    cout << tmp << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << res[i].first << " " << res[i].second << endl;
    }
    return 0;
}