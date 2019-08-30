/*
	简单题想复杂了  其实应该直接用数组去存 存不下 10000 * 10000 的 其实完全可以直接用 vector<int> v[10000]去存的 
    有时间再写一遍 不知道问题出在哪 可能就 是出在了 映射上
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
int n,m,k;
const int maxn = 305;
struct Node {
    string id;
    bool gad;
    int pos;
}node[maxn];

map<string,int> p;
vector<pair<string,string> >res;
bool mmap[maxn][maxn];
vector<int>ms[maxn];


bool cmp (const pair<string,string> &p1,const pair<string,string> &p2) {
    if (p1.first != p2.first) return p1.first <= p2.first;
    return p1.second < p2.second;
}

int main()
{
    cin >> n >> m;
    string a,b;
    int tot = 1;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        if (p[a] == 0) p[a] = tot++;
        int ida = p[a];  

        node[ida].id = a;
        node[ida].pos = tot;
        if (a[0] == '-') node[ida].gad = true;
        else node[ida].gad = false;
        
        if (p[b] == 0) p[b] = tot++;
        int idb = p[b];
        node[idb].id = b;
        node[idb].pos = tot;
        if (b[0] == '-') node[idb].gad = true;
        else node[idb].gad = false;
        
        mmap[ida][idb] = mmap[idb][ida] = true;
        if (node[ida].gad == node[idb].gad) {
            ms[ida].push_back(idb);
            ms[idb].push_back(ida);
        }
    }

    cin >> k;
    for (int i = 0; i < k; i++) {
        res.clear();
        cin >> a >> b;
        int x = p[a];
        int y = p[b];
        bool i1 = node[x].gad;
        bool i2 = node[y].gad;
        for (int i = 0;i < ms[x].size(); i++) {
            int u = ms[x][i];
            for (int j = 0; j < ms[y].size(); j++) {
                int v = ms[y][j];
                if (mmap[u][v]) {
                    a = node[u].id;
                    b = node[v].id;
                    if (node[u].gad == true) {
                        a = a.substr(1);
                    }
                    if (node[v].gad == true) {
                        b = b.substr(1);
                    }
                    res.push_back(make_pair(a,b));
                }
            }
        }
        if (res.empty()) {
           cout << 0 << endl;
           continue;
        }
        sort(res.begin(),res.end(),cmp);
        cout << res.size() << endl;
        for (int i = 0; i < res.size(); i++) {
            cout << res[i].first << " " << res[i].second << endl;
        }

    }
    
    return 0;
}