/*
	这道题最先开始真的是不知道何从入手，因为本身对于图论的相关知识并不是特别在行

    这道题的两种方法，第一就是并查集，第二就是利用dfs遍历完所有需要遍历的点。
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

int N,M,K;

const int maxn = 1005;
int fa[maxn];
//再次错在了这种地方，范围小了，这里题目虽然并没有给出相应的范围
//但是按照每一条边之间的链接来看，这里需要加大其的范围。
pair<int,int> pp[maxn * maxn];


void init() {
    for (int i = 0; i <= N; i++) {
        fa[i] = i;
    }

}

int find(int x) {
    if (fa[x] != x) fa[x] = find(fa[x]);
    return  fa[x];
}

void merge(int x,int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx != fy) {
        fa[fx] = fy;
    }
}

int main()
{
	std::ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> K;
    int a,b;

    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        pp[i].first = a;
        pp[i].second = b;
    }
    int tmp;
    for (int i = 0; i < K; i++) {
        cin >> tmp;
        init();
        for (int j = 0; j < M; j++) {
            if (pp[j].first != tmp && pp[j].second != tmp) {
                merge(pp[j].first,pp[j].second);
            }
        }

        int cnt = 0;
        for (int i = 1; i <= N; i++) {
            if (fa[i] == i) cnt++;
        }

        if (N == 1) cout << 0 << endl;
        else if (N == 2) cout << 0 << endl;
        else

        cout << cnt - 2 << endl;
    }
    
	
    return 0;
}