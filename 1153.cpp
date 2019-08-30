/*
	有的时候用map 可能会超时，所以这个时候就需要使用到 
    unordered_map
    这个是利用哈希表建造的  insert应该会很快，但是查询的时候会很慢
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <queue>
#include <unordered_map>
#include <cmath>

using namespace std;
struct Node
{
    string id;
    int sco;
};
bool cmp(Node a, Node b)
{
    if (a.sco != b.sco)
        return a.sco > b.sco;
    else
        return a.id < b.id;
}

int main()
{
    int n, query, type;
    cin >> n >> query;
    vector<Node> node(n);
    for (int i = 0; i < n; i++)
    {
        cin >> node[i].id >> node[i].sco;
    }
    for (int i = 0; i < query; i++)
    {
        string temp;
        cin >> type >> temp;
        printf("Case %d: %d %s\n", i + 1, type, temp.c_str());
        vector<Node> ans;
        int cnt = 0, sum = 0;
        if (type == 1)
        {
            for (int j = 0; j < n; j++)
            {
                if (temp[0] == node[j].id[0])
                    ans.push_back(node[j]);
            }
        }
        else if (type == 2)
        {
            for (int j = 0; j < n; j++)
            {
                string str = node[j].id.substr(1, 3);
                if (str == temp)
                {
                    cnt++;
                    sum += node[j].sco;
                }
            }
            if (cnt != 0)
            {
                cout << cnt << " " << sum << endl;
                continue;
            }
            else if (cnt == 0)
                cout << "NA\n";
        }
        else if (type == 3)
        {
            unordered_map<string, int> m;
            for (int j = 0; j < n; j++)
            {
                string str = node[j].id.substr(4, 6);
                if (temp == str)
                    m[node[j].id.substr(1, 3)]++;
            }
            for (auto it : m)
                ans.push_back({it.first, it.second});
        }
        sort(ans.begin(), ans.end(), cmp);
        for (int k = 0; k < ans.size(); k++)
        {
            printf("%s %d\n", ans[k].id.c_str(), ans[k].sco);
        }
        if (((type == 1 || type == 3) && ans.size() == 0))
            cout << "NA\n";
    }
    return 0;
}