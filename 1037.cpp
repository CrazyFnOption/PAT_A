/*
	这个题目有点侮辱我的智商，我就压根没有想到原来这道题这么简单，简单到另外怀疑人生。
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

const int maxn = 1e5 + 10;
long long coupon[maxn];
long long coupon_[maxn];
long long product[maxn];
long long product_[maxn];

bool  cmp (int a,int b) { return a > b;}
int main()
{
    int nc,np;
    long long tmp;
    int ctot = 0,ctot_ = 0;
    int ptot = 0,ptot_ = 0;
    scanf("%d",&nc);
    for (int i = 0;i < nc; i++) {
        scanf("%lld",&tmp);
        if (tmp == 0) continue;
        if (tmp > 0) coupon[ctot++] = tmp;
        else coupon_[ctot_++] = tmp;
    }

    sort(coupon,coupon + ctot,cmp);
    sort(coupon_,coupon_ + ctot_);
    scanf("%d",&np);

    for (int i = 0; i < np; i++) {
        scanf("%lld",&tmp);
        if (tmp == 0) continue;
        if (tmp > 0) product[ptot++] = tmp;
        else product_[ptot_++] = tmp;
    }

    sort(product,product + ptot,cmp);
    sort(product_,product_ + ptot_);
	
    int ans = min(ctot,ptot);
    long long res = 0;

    for (int i = 0; i < ans; i++) {
        res += coupon[i] * product[i];
    }
    ans = min(ctot_,ptot_);
    for (int i = 0; i < ans; i++) {
        res += coupon_[i] * product_[i];
    }

    printf("%lld",res);
    return 0;
}