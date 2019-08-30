/*
	其实这段题目有一定的误解性，题目直接给出的十进制，
    意思是先进行进制的转化，然后在逆转，然后再转化为十进制。

    强烈要求记住 1 0 这两个地方的位置 不属于质数！！！
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

int n,radix;

const int maxn = 1e6 + 5;
bool isprime[maxn];
int prime[maxn];
int tot;

string s;
void get_prime() {
    tot = 0;
    
    memset(isprime,true,sizeof isprime);
    for (int i = 2; i < maxn; i++) {
        if (isprime[i]) prime[tot++] = i;
        for (int j = 0; j < tot; j++) {
            if (i * prime[j] >= maxn) break;
            isprime[i * prime[j]] = false;
            if (i % prime[j] == 0) break;
        }
    }
    // what the fuck ????
    //这个地方的bug我找了半个小时
    //最后注意到 1 和 0 不属于质数。
    isprime[1] = false;
    isprime[0] = false;
}

int get_num() {
    int tmp;
    while (n > 0) {
        tmp = n % radix;
        n = n / radix;
        s.push_back((tmp + '0'));
    }

    tmp = 0;
    //cout << s << endl;
    int i = 0;
    for (auto it = s.rbegin(); it != s.rend();it++) {
        tmp += (*it - '0') * pow(radix,i++);
    }
    //cout << tmp << endl;
    return tmp;
}

int main()
{
	std::ios::sync_with_stdio(false);
    get_prime();
	while (cin >> n && n >= 0) {
        cin >> radix;
        s = "";
        if (!isprime[n]) {
            cout << "No" << endl;
            continue;
        }
        
        //cout << get_num () << endl;

        if (!isprime[get_num()]) {
            cout << "No" << endl;

        }
        else cout << "Yes" << endl;
        
    }
    return 0;
}