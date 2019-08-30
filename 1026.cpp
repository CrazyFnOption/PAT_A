/*
	rounded up 竟然是四舍五入的意思，竟然不是向上取整的意思。
    
    其次就是题目没有说清楚的地方
    最为重要的一点，当有普通球台和VIP球台时，
    VIP客户遵循选择最小编号的VIP球台（VIP就要这么任性），
    而非编号最小的球台；普通客户遵循选择最小的球台

    这道题 自己还有一个样例没有过，就是只得了28分 需要思考为什么。
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

const int maxn = 1e4 + 10;
struct People {
    int ct;
    int et;
    int used;
    int st;
    int wt;
    int vip;
    bool operator < (const People &p) const {
        return ct < p.ct;
    }
}people[maxn];

struct window {
    int num;
    int vip;
    int dt ;

    window(int a = 8 * 3600,int b = 0) :dt(a),num(b),vip(b){}
}win[100 + 10];

bool cmp (const People &p,const People & o) {
    return p.st < o.st;
}

int main()
{
    int N;
    scanf("%d",&N);
    int h,m,s,et,vip;
    vector<int> _vip;
    int tmp,cnt = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d:%d:%d %d %d",&h,&m,&s,&et,&vip);
        tmp = h * 3600 + m * 60 + s;
        if (tmp >= 21 * 3600) cnt++;
        if (et > 120) et = 120;
        people[i].ct = tmp;
        people[i].et = et * 60;
        people[i].used = 0;
        people[i].vip = vip;
    }
    sort(people,people+N);
    N = N - cnt;
    for (int i = 0; i < N; i++) {
        if (people[i].vip == 1) _vip.push_back(i);
    }
    
    int M,K;
    scanf("%d %d",&M,&K);
    int a;
    for (int i = 0; i < K; i++) {
        scanf("%d",&a);
        win[a].vip = 1;
    }
    int Min,index;
    int tnt = 0;
    int vipmin;
    int vipindex;
    for (int i = 0; i < N; ) {
        Min = vipmin = 0x3f3f3f3f;
        index = vipindex = -1;
        if (people[i].used == 1) {
            i++;
            continue;
        }

        for (int j = 1; j <= M; j++) {
            if (Min > win[j].dt) {
                Min = win[j].dt;
                index = j;
            }
        }

        for (int j = 1; j <= M; j++) {
            if (Min == win[j].dt && win[j].vip == 1) {
                vipmin = Min;
                vipindex = j;  
                break;     
            } 
        }
        
        if (win[index].vip == 1) {
            if (tnt < _vip.size()) {
                    while (tnt < _vip.size()) {
                        if (people[_vip[tnt]].used == 0) break;
                        tnt++;
                    }
                    if (people[_vip[tnt]].ct <= win[index].dt) {
                        people[_vip[tnt]].st = win[index].dt;
                        people[_vip[tnt]].wt = win[index].dt - people[_vip[tnt]].ct;
                        people[_vip[tnt]].used = 1;
                        win[index].dt += people[_vip[tnt]].et;
                        tnt++;
                        win[index].num++;
                        continue;
                    }
            }
        }

        if (index < vipindex && people[i].vip == 1) {
            people[i].used = 1;
            people[i].st = max(win[vipindex].dt, people[i].ct);
            if (people[i].st >= 21 * 3600)
            {
                i++;
                continue;
            }
            people[i].wt = win[vipindex].dt - people[i].ct;
            people[i].used = 1;
            win[vipindex].dt = people[i].st + people[i].et;
            win[vipindex].num++;
            i++;
            continue;
        }


        people[i].st = max(win[index].dt,people[i].ct);
        
        people[i].wt = win[index].dt - people[i].ct;
        people[i].used = 1;
        if (people[i].st >= 21 * 3600)
        {
            i++;
            continue;
        }
        win[index].dt =people[i].st + people[i].et;
        
        win[index].num++;
        i++;
    }

    sort(people,people + N,cmp);

    for (int i = 0; i < N; i++) {
        int tt = (people[i].wt + 30) / 60;
        if (tt < 0) tt = 0;
        

        if (people[i].st >= 21 * 3600) break;
        printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",
               people[i].ct / 3600, people[i].ct / 60 % 60, people[i].ct%60,
               people[i].st / 3600, people[i].st / 60 % 60, people[i].st%60,tt);
    }
    printf("%d",win[1].num);
    for (int i = 2; i <= M; i++) {
        printf(" %d",win[i].num);
    }

    return 0;
}