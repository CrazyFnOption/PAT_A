/*
	第一次写的时候看错题，第一个独立的数字，将会直接输出结果

    简单题目。
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<cstdio>
#include<queue>
#include<map>
#include<cmath>

using namespace std;

map<int,int>m;
vector<int>v;


int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
    int n;
    cin >> n;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        m[x]++;
        v.push_back(x);
        
    }
        for (int i = 0; i < v.size(); i++) {
            if (m[v[i]] == 1) {
                cout << v[i] << endl;
                return 0;
            }
        }
        cout << "None" << endl;
    
	
    return 0;
}