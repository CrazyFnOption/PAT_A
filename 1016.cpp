#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <cmath>
#include <set>

using namespace std;

const string on = "on-line";
const string off = "off-line";


struct Record
{

    string status;
    int month;
    int day;
    int hour;
    string name;
    int minute;
    int t;

    Record(){};
    //这个地方还是需要注意一下 关于时间日期的登记方式。
    //substr(第一个数的坐标，后面一个数的坐标加1)
    Record(int a, int b, int c, int d, const string &e) : month(a), day(b), hour(c), minute(d), status(e) {}

    bool operator<(const Record &r) const
    {
        if (name == r.name) {
            return t < r.t;
        }
        return name < r.name;
    }
}record[1005];

map<string, vector<Record> > m;
int cost[30];
double zeroToNowBill(const Record &u)
{ //从月初到当前时间通话费用.
    double total = 0.0;
    total += 60 * cost[24] * u.day + cost[u.hour] * u.minute;
    for (int i = 0; i < u.hour; ++i)
        total += cost[i] * 60;
    return total / 100; // 美分->美元
}
int N;


int main()
{
    int ans = 0;
    for (int i = 0; i < 24; i++)
    {
        scanf("%d",&cost[i]);
        ans += cost[i];
    }

    cin >> N;
    string name, _time, status;
    int month, day, hour, minute;
    for (int i = 0; i < N; i++)
    {
        cin >> name ;
        scanf("%d:%d:%d:%d", &month, &day, &hour, &minute);
        cin >> status;
        record[i].name = name;
        record[i].month = month;
        record[i].day = day;
        record[i].hour = hour;
        record[i].minute = minute;
        record[i].status = status;
        record[i].t = hour * 60 + minute + day * 24 * 60;
    }
    sort(record,record+N);
    for (int i = 1;i < N; i++) {
        if (record[i].name == record[i - 1].name && record[i].status == off && record[i - 1].status == on)
        {
            m[record[i].name].push_back(record[i - 1]);
            m[record[i].name].push_back(record[i]);
        }
    }
    

    for (map<string, vector<Record> >::iterator it= m.begin();it != m.end(); it++)
    {
        vector<Record> &v = it->second;
        printf("%s %02d\n", v[0].name.c_str(), v[0].month);
        
        double sum = 0;
        
        //for (auto i:v) cout << i.hour << endl;
        for (int i = 0; i < v.size(); i++)
        {
        
            int cost_ = 0;
            double money = zeroToNowBill(v[i]) - zeroToNowBill(v[i - 1]);
            double mm = (double)money / 100.0;
            cost_ = v[i].t - v[i - 1].t;
            sum += mm;
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n",
                   v[i - 1].day, v[i - 1].hour, v[i - 1].minute, v[i].day, v[i].hour, v[i].minute, cost_, mm);
            i++;
        }
        printf("Total amount: $%.2lf\n", sum);
    }
    return 0;
}