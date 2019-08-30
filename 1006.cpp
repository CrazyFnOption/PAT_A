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

 
struct node {
    string name;
    string _beg,_end;

    int time_beg,time_end;

    node (){}
    node (string a,string b,string c) :name(a),_beg(b),_end(c){
        time_beg = stoi(b.substr(0,2)) * 60 * 60 + stoi(b.substr(3,5)) * 60 + stoi(b.substr(6,8));
        time_end = stoi(c.substr(0,2)) * 60 * 60 + stoi(c.substr(3,5)) * 60 + stoi(c.substr(6,8));
    };

    bool operator < (const node & n) const {
        return time_beg < n.time_beg;
    }
};

bool cmp (const node &a, const node &b) {
    return a.time_end > b.time_end;
}

int main()
{
	std::ios::sync_with_stdio(false);
    int m;
    cin >> m;
    node n[m + 5];
	string a,b,c;

    for (int i = 0; i < m ; i++) {
        cin >> a >> b >> c;
        node tmp(a,b,c);
        n[i] = tmp;
        //cout << n[i].time_beg << endl;
    }
    if (m == 1) {
        cout << a << " " << a << endl;
        return 0;
    }

    sort(n,n+m);
    cout << n[0].name << " ";
    sort(n,n+m,cmp);
    cout << n[0].name << endl;;
    
    return 0;
}