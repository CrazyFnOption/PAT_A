/*
	这道30分的题目 真的有失水准 很简单的一道水题，就是判断条件要复杂一点罢了

    水题 希望到时候考试的时候也是这样的一道水题。
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

int n, m, k;

struct Applicant {
    int Ge;
    int Gi;
    double fin;
    int id;
    vector<int>v;
    int rank;

    bool operator < (const Applicant &a) const {
        if (fin != a.fin) return fin > a.fin;
        return Ge > a.Ge;
    }

}applicant[40005];

vector<int>res[105];
int school[105];

int main()
{
    scanf("%d %d %d",&n,&m,&k);
    for (int i = 0; i < m; i++) {
        scanf("%d",&school[i]);
    }
    int tmp;
    for (int i = 0; i < n; i++) {
        scanf("%d %d",&applicant[i].Ge,&applicant[i].Gi);
        applicant[i].id = i;
        applicant[i].fin = (double)(applicant[i].Ge + applicant[i].Gi) / 2.0;
        for (int j = 0; j < k; j++) {
            scanf("%d",&tmp);
            applicant[i].v.push_back(tmp);
        }
    }
    
    sort(applicant,applicant + n);
    bool flag = false;
    int last = -1;
    for (int i = 0; i < n; i++) {
        flag = false;
        if (i > 0) {
            if (applicant[i].fin == applicant[i - 1].fin && applicant[i].Ge == applicant[i - 1].Ge) {
                flag = true;
            }
        }
        for (int j = 0; j < applicant[i].v.size(); j++) {
            tmp = applicant[i].v[j];
            if (flag && last == tmp) {
                res[tmp].push_back(applicant[i].id);
                break;
            }
            if (res[tmp].size() < school[tmp]) {
                res[tmp].push_back(applicant[i].id);
                last = tmp;
                break;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        if (res[i].empty()) printf("\n");
        else {
            sort(res[i].begin(),res[i].end());
            printf("%d",res[i][0]);
            for (int j = 1; j < res[i].size();j++) printf(" %d",res[i][j]);
            printf("\n");
        }
    }

    return 0;
}