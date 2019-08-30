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


int main()
{
	std::ios::sync_with_stdio(false);
	string s;
    cin >> s;
    int sum = 0;
    map<char,string>m;

    m['0'] = "zero";
    m['1'] = "one";
    m['2'] = "two";
    m['3'] = "three";
    m['4'] = "four";
    m['5'] = "five";
    m['6'] = "six";
    m['7'] = "seven";
    m['8'] = "eight";
    m['9'] = "nine";

    int num ;

    for (int i = 0; i < s.size(); i++) {
        num = s[i] - '0';
        sum += num;
    }

    string ss = to_string(sum);
    
    cout << m[ss[0]];
    for (int i = 1; i < ss.size(); i++) {
        cout << " " << m[ss[i]];
    }
    cout << endl;

    return 0;
}