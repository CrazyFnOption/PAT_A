/*
	这道题是真的很难，我真的不知道该如何去思考这一个问题，

    因为我所想到的所有办法基本上全部属于超时的行为。

    有的做法直接分成左右两边进行求解，而有的做法是直接使用数位dp

    下面这张做法我比较欣赏：
    思路：对于整数，我们计算他前一位 前俩位 前三位 等等的 含有1的个数，比如

个位只有 1
十位和个位共有 （9*1 +）(1-9 数的个位是1的数量 和十位是1的数量）+ 个位数量 1 = 20
百位 （9*20 +  ）+ 20= 300；
此位不是1时 到此位时所有的有1的数数量 和此位是1是 数量和，重复数使得计算出数字中1的个数。

如果有大小限制的话。

此位为0时 没有增加数量，因为 012 就是 12 本身。

此位为1时，totalsum += (n%num+1) （就像123  从 100到 123）;      totalsum += bitsum (就像 123 上十位个位 0-99中1的个数）;

此位为>1时，totalsum += bitallsum (就是 100-199）;  totalsum += (part)*bitsum （0-99含1个数×part);

*/
#include <iostream>
#include <string>
using namespace std;
long long deal(long long n);
int main()
{
    long long n;
    while (cin >> n)
        cout << deal(n) << endl;
    return 0;
}
long long deal(long long n)
{
    long long totalsum = 0;
    long long bitallsum = 1;
    //低一位所包含的 1的个数 就像上面所推导出来的式子一样
        long long bitsum = 0;
    long long num = 1;
    while (n / num)
    {
        long long part = (n / num) % 10;
        if (part == 1)
        {
            // 如果等于1 那么久看这个位置中 百位数上满足一的位置  
            //举个例子 从100 到 123 一共24个数 百位数上面都是有1的
            totalsum += (n % num + 1);
            //这一步就加上到100之前的数
            totalsum += bitsum;
            //可能就会有疑问 毕竟从100 到 123 之间不止百位上面的1被计算出来了
            //但是之前的计算都是依次向前面的计算的 意思就是 前面的位数 其实前面都已经计算出来了。
        }
        else if (part > 1)
        {
            //还是沿用上面的例子 如果 为323 那么 这里就是要加上100到199百位上面的数字
            //所以这个地方要加上。
            totalsum += bitallsum;
            //这里要加上3 乘以 低一位所代表的数，不用乘以1的，但是要算上的是 0 到99
            totalsum += (part)*bitsum;
        }
        //这里就是上面的公式 需要往下面一位去进
        bitsum += (9 * bitsum + bitallsum);
        bitallsum *= 10;
        num *= 10;
    }
    return totalsum;
}