/*
	这道题写大代码量有点多，主要是重复的代码太多了，应该使用函数去解决问题，这样一来代码简洁很多，这里需要注意

    另外 这道题刚开始写的时候出现的问题就在于 每次排序可能存在并列的情况，那么这里排名的时候就不能这样一次往下面写。

    像我下面所使用的一样，直接使用一个flag变量计算重复的究竟有多少个。
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

const int maxn = 2000 + 5;

struct person {
    string id;
    int cp;
    int mp;
    int ep;
    int avi;

    int rank_avi;
    int rank_cp;
    int rank_mp;
    int rank_ep;

    string res;

    person(){}
    person(const string &s,int a,int b,int c) : id(s),cp(a),mp(b),ep(c) ,avi((a + b + c) / 3){}

    bool operator < (const person & p) const {
        return avi > p.avi;
    }
};

bool cmp1(const person &a,const person &b)  {
    return a.cp > b.cp;
}

bool cmp2(const person &a,const person &b)  {
    return a.mp > b.mp;
}

bool cmp3(const person &a,const person &b)  {
    return a.ep > b.ep;
}


int main()
{
	std::ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    string id;
    int a,b,c;
    map<string,person> mv;
    vector<person> v;
    for (int i = 0; i < n; i++) {
        cin >> id >> a >> b >> c;
        v.push_back(person (id,a,b,c));
    }

    int flag = 0;
    sort(v.begin(),v.end());
    v[0].rank_avi = 1;
    for (int i = 1 ; i < n; i++) {
        if (v[i].avi == v[i - 1].avi){
            v[i].rank_avi = v[i - 1].rank_avi;
            flag++;
        }
        else {
            v[i].rank_avi = v[i - 1].rank_avi + 1 + flag;
            flag = 0;
        }
    }

    sort(v.begin(),v.end(),cmp1);
    v[0].rank_cp = 1;
    for (int i = 1 ; i < n; i++) {
        if (v[i].cp == v[i - 1].cp){
            v[i].rank_cp = v[i - 1].rank_cp;
            flag++;
        }
        else {
            v[i].rank_cp = v[i - 1].rank_cp + 1 + flag;
            flag = 0;
        }
    }

    sort(v.begin(),v.end(),cmp2);
    v[0].rank_mp = 1;
    for (int i = 1 ; i < n; i++) {
        if (v[i].mp == v[i - 1].mp){
            v[i].rank_mp = v[i - 1].rank_mp;
            flag++;
        }
        else {
            v[i].rank_mp = v[i - 1].rank_mp + 1 + flag;
            flag = 0;
        }
    }

    sort(v.begin(),v.end(),cmp3);
    v[0].rank_ep = 1;
    mv[v[0].id] = v[0];
    
    for (int i = 0 ; i < n; i++) {
        if (i == 0) {
             v[0].rank_ep = 1;
        }
        else {
            if (v[i].ep == v[i - 1].ep){
                v[i].rank_ep = v[i - 1].rank_ep;
                flag++;
            }
            else {
                v[i].rank_ep = v[i - 1].rank_ep + 1 + flag;
                flag = 0;
            }
        }
        v[i].res = "";
        int Min = 0x3f3f3f3f;
        char mm;

        if (Min > v[i].rank_avi) {
            Min = v[i].rank_avi;
            mm = 'A';
        }

        if (Min > v[i].rank_cp) {
            Min = v[i].rank_cp;
            mm = 'C';
        }

        if (Min > v[i].rank_mp) {
            Min = v[i].rank_mp;
            mm = 'M';
        }

        if (Min > v[i].rank_ep) {
            Min = v[i].rank_ep;
            mm = 'E';
        }
        string tmp = to_string(Min);

        v[i].res = tmp + " " + mm;

        mv[v[i].id] = v[i];
    }

    string s;
    for (int i = 0; i < m; i++) {
        cin >> s;
        auto it = mv.find(s);
        if (it != mv.end()) {
            cout << (it -> second).res << endl;
        }
        else cout << "N/A" << endl;

    }

    return 0;
}