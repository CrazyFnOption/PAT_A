/*
	看到这道题 我还在疑惑，为什么7，6，5，4，3，2，1 不能完成任务

    最后发现原来栈的容量也是有限的，看清楚题目。
*/
#include<iostream>
#include<vector>
#include<stack>

using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    int m, n, k;
    cin >> m >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int cnt = 1;
        stack<int> st;
        vector<int> ppp;
        ppp.resize(n + 1);
        for (int j = 1; j <= n; j++)
        {
            cin >> ppp[j];
        }
        for (int j = 1; j <= n; j++)
        {
            st.push(j);
            //这里必须要强调的是，因为栈的长度是不能超过m的，
            //一旦超过就不属于题目的条件。
            if (st.size() > m)
                break;
            while (!st.empty() && st.top() == ppp[cnt])
            {
                st.pop();
                cnt++;
            }
        }
        if (cnt == n + 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
