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

struct Node {
    int next;
    int val;
    int address;
}node[1000005];

vector<int>_res;
vector<int> mid;
vector<int>res;

int main()
{
    
    int first,n,k;
    scanf("%d %d %d",&first,&n,&k);
    int a,b,c;
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d",&a,&b,&c);
        node[a].address = a;
        node[a].val = b;
        node[a].next = c;
    }
    while (first != -1) {
        if (node[first].val > k) res.push_back(first);
        else if (node[first].val < 0) _res.push_back(first);
        else mid.push_back(first);
        first = node[first].next;
    }
    for (int i = 0; i < _res.size(); i++) {
        if (i != _res.size() - 1) printf("%05d %d %05d\n",node[_res[i]].address,node[_res[i]].val,node[_res[i + 1]].address);
        else {
            if (!mid.empty())            
                printf("%05d %d %05d\n",node[_res[i]].address,node[_res[i]].val,node[mid[0]].address);
            else if (!res.empty())
                printf("%05d %d %05d\n",node[_res[i]].address,node[_res[i]].val,node[res[0]].address);
            else printf("%05d %d %d",node[_res[i]].address,node[_res[i]].val,-1);
        }
    }

    for (int i = 0; i < mid.size(); i++) {
        if (i != mid.size() - 1)
            printf("%05d %d %05d\n", node[mid[i]].address, node[mid[i]].val, node[mid[i + 1]].address);
        else {
            if (!res.empty())
                printf("%05d %d %05d\n", node[mid[i]].address, node[mid[i]].val, node[res[0]].address);
            else
                printf("%05d %d %d", node[mid[i]].address, node[mid[i]].val, -1);
        }
    }

    for (int i = 0; i < res.size(); i++) {
        if (i != res.size() - 1)
            printf("%05d %d %05d\n", node[res[i]].address, node[res[i]].val, node[res[i + 1]].address);
        else
            printf("%05d %d %d", node[res[i]].address, node[res[i]].val, -1);
    }
    return 0;
}