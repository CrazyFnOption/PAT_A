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

int N,M,K,Q;

struct people {
    people(){};
    int id;
    int time;
    int last;
    int start_time;
    int leave_time;
};

queue<people> q[35];
people p[1005];

int len;
bool flag;
int current = 0;

void get_ready() {
    for (int i = 0; i < len; i++) {
        int mo = i % N;
        q[mo].push(p[i]);   
    }
}

void caculate() {
    int Min = 0x3f3f3f3f;
    int index = 0;
    int _id;
    
    for (int i = 0; i < M; i++) {
        if (!q[i].empty()) {
            if (Min > q[i].front().time) {
                Min = q[i].front().time;
                index = i;
                _id = q[i].front().id;
            }
        }
    }
    if (Min == 0x3f3f3f3f) return;
    
    
    for (int i = 0; i < M; i++) {
        if (i == index) continue;
        if (!q[i].empty())
            q[i].front().time = q[i].front().time - Min;
            if (q[i].front().time == 0) q[i].front().last = Min;
    }
    if (Min == 0) {
        p[_id].start_time = current - q[index].front().last;
    }
    else p[_id].start_time = current;

    current += Min;
    p[_id].leave_time = current;
    q[index].pop();
    if (current >= 540) return;
    if (!flag && len < K) {
        q[index].push(p[len++]);
    }
    
    
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M >> K >> Q;
    
    for (int i = 0; i < K; i++) {
        cin >> p[i].time;
        p[i].id = i;
        p[i].start_time = -1;
    }
    
    len = N * M;
    flag = false;
    //这种情况就是 全部人数都进去了 还是不满的情况
    if (K < len) {
        len = K ;
        flag = true;
    }
    get_ready();
    
    for (int i = 0; i < K; i++) {
        if (current >= 540) {
            break;
        }
        caculate();
    }

    int tmp;
    for (int i = 0; i < Q; i++) {
        cin >> tmp;
        int x = p[tmp - 1].leave_time;
        int y = p[tmp - 1].start_time;
        if (y >= 540 || y == -1) {
            printf("Sorry\n");
        }
        else {

            int hour = x / 60;
            int minute = x % 60;
            printf("%02d:%02d\n",8 + hour,minute);
        }
    }

    return 0;
}

/*
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct Node{
    int id, time;
};
int main(){
    int n, m, k, q, i, j;
    scanf("%d %d %d %d", &n, &m, &k, &q);
    vector<int> finishTime(k+1), trans(k+1);
    for(i=1; i<=k; i++) scanf("%d", &trans[i]);
    vector<queue<Node> > window(n);
    for(i=1; i<=k; i++){
        int minLenth=0, fisrtFinish=0;
        Node node; node.id=i;
        for(j=0; j<n; j++){
            if(window[j].size()==0){
                minLenth = j;
                break;
            }else{//找到最先结束和最短的队列
                if(window[j].size()<window[minLenth].size()) minLenth = j;
                if(window[j].front().time<window[fisrtFinish].front().time) fisrtFinish = j;
            }
        }
        if(window[minLenth].size()<m){//当队列没有排满的时候， 排到最短的队列后面
            if(window[minLenth].size()!=0) node.time = window[minLenth].back().time+trans[i];
            else node.time = 480+trans[i];
            window[minLenth].push(node);
            finishTime[i] = node.time;
        }else{//当队列满了之后，排到最先结束的队列
            node.time = window[fisrtFinish].back().time+trans[i];
            window[fisrtFinish].pop();
            window[fisrtFinish].push(node);
            finishTime[i] = node.time;
        }
    }

    for(i=0; i<q; i++){
        int qry;
        scanf("%d", &qry);
        if(finishTime[qry]-trans[qry] >= 17*60) printf("Sorry\n");
        else printf("%02d:%02d\n", finishTime[qry]/60, finishTime[qry]%60);
    }
    return 0;
 */