/*
	简单的字符串处理，就是将string 里面字符串进行一个简单处理
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
inline void deal(char &c);
int main()
{
    int n;
    cin >> n;
    string account, password, tmp;
    vector<pair<string, string> > vpair;
    for (int i = 0; i < n; ++i)
    {
        cin >> account >> password;
        tmp = password;
        bool f = 0;
        for (int i = 0; i < password.size(); ++i)
        {
            deal(password[i]);
        }
        if (tmp != password)
        {
            vpair.push_back(make_pair(account, password));
        }
    }
    if (vpair.size() != 0)
    {
        cout << vpair.size() << endl;
        for (int i = 0; i < vpair.size(); ++i)
        {
            cout << vpair[i].first << ' ' << vpair[i].second << endl;
        }
    }
    else
    {
        if (n == 1)
            cout << "There is 1 account and no account is modified" << endl;
        else
            cout << "There are " << n << " accounts and no account is modified" << endl;
    }
    system("pause");
    return 0;
}
void deal(char &c)
{
    if (c == '1')
        c = '@';
    else if (c == '0')
        c = '%';
    else if (c == 'l')
        c = 'L';
    else if (c == 'O')
        c = 'o';
}