/*
	简单的排序题目 有点浪费精力，不过还是写一下 免得到时候不会写了。
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

struct node {
    int id;
    int tal;
    int vir;
    node (int a = 0,int b = 0, int c = 0) :id(a),vir(b),tal(c){}

    bool operator< (const node &n) const {
        int x = tal + vir;
        int y = n.tal + n.vir;
        if (x == y) {
            if (vir == n.vir) return id < n.id;
            return vir > n.vir;
        }

        return x > y;
    }
};

vector<node> vs;
vector<node> vn;
vector<node> vf;
vector<node> vo;

void print(const vector<node> &v) {
    for (int i = 0; i < v.size(); i++) {
        printf("%08d %d %d\n",v[i].id,v[i].vir,v[i].tal);
    }
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
    int n,l,h;
    int cnt = 0;
    cin >> n >> l >> h;
    int a,b,c;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        if (b < l || c < l) {
            cnt++;
            continue;
        }
        if (b >= h && c >= h) {
            vs.push_back(node(a,b,c));
            continue;
        }

        if (b >= h) {
            vn.push_back(node(a,b,c));
            continue;
        }

        if (b >= c) {
            vf.push_back(node(a,b,c));
            continue;
        }
        vo.push_back(node(a,b,c));
    }
    cout << n - cnt << endl;
    sort(vs.begin(),vs.end());
    print(vs);
    sort(vn.begin(),vn.end());
    print(vn);
    sort(vf.begin(),vf.end());
    print(vf);
    sort(vo.begin(),vo.end());
    print(vo);

    return 0;
}