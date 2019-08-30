#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
#define INF 0x3f3f3f3f
 
using namespace std;
typedef long long ll;
const int maxn = 2010;
int per[maxn],num[maxn];
map<string,int> names;
queue<pair<string,string> > que;
string _next[maxn];
 
int n,k;
struct people
{
    string name;
    int lenth;
}peo[maxn];
 
 
void Init()
{
    for(int i = 1;i <= 2*n;i ++) per[i] = i;
}
int Find(int x)
{
    return  x == per[x] ? x:per[x] = Find(per[x]);
}
 
void Union(int x,int y)
{
    x = Find(x);
    y = Find(y);
    if(x != y)
    {
        //并查集的空间优化
        if(peo[x].lenth > peo[y].lenth)
            per[y] = x;
        else
            per[x] = y;
    }
}
 
int main()
{
    scanf("%d%d",&n,&k);
    Init();
    getchar();
    string name1,name2;
    int len,index = 0;
    for(int i = 1;i <= n;i ++)
    {
        cin>>name1>>name2>>len;
        if(!names[name1]){
            names[name1] = ++index;
            peo[index].name = name1;
            peo[index].lenth = len;
        }
        else
            peo[names[name1]].lenth += len;
        if(!names[name2]){
            names[name2] = ++index;
            peo[index].name = name2;
            peo[index].lenth = len;
        }
        else
            peo[names[name2]].lenth += len;
        que.push(make_pair(name1,name2));
    }
//    for(int i = 1;i <= index;i ++)
//        cout << peo[i].name<<" "<<peo[i].lenth<<endl;
    pair<string,string> p;
    while(!que.empty())
    {
        p = que.front();que.pop();
        Union(names[p.first],names[p.second]);
    }
    for(int i = 1;i <= index;i ++)
    {
        int x = Find(i);
        if(per[i] != i)
            peo[x].lenth += peo[i].lenth;
        num[x] ++;
    }
//    for(int i = 1;i <= index;i ++)
//        cout << peo[i].name<<" "<<peo[i].lenth<<endl;
 
    int pos = 0;
    for(int i = 1;i <= index;i ++)
    {
        if(num[i] > 2 && peo[i].lenth > k*2)
            _next[++pos] = peo[i].name;
    }
    if(pos == 0)
        printf("0\n");
    else{
        printf("%d\n",pos);
        sort(_next+1,_next+pos+1,less<string>());
        for(int i = 1;i <= pos;i ++)
            cout << _next[i] << " "<<num[names[_next[i]]]<<endl;
    }
}