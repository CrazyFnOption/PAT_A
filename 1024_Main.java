
/*
    感觉pat里面考大数的题目也有点多，需要花点时间重新温习一下
    
    java 里面一些string stringBuilder StringBuffer 相关的函数

    还需要弄清楚的是各种不能在一起使用问题，以及相互转换的问题，尤其是char 与 string类型
*/
import java.util.Scanner;
import java.math.BigInteger;

public class 1024_Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int k;
        BigInteger n,a,b;
        n = in.nextBigInteger();
        k = in.nextInt();
        a = n;
        String sa,sb;
        StringBuilder s = new StringBuilder(n.toString());
        StringBuilder xs = new StringBuilder(n.toString());
        for (int i = 0; i <= k; i++) {
            
            xs = new StringBuilder(a.toString());
            s = new StringBuilder(a.toString());
            s.reverse();
            sa = s.toString();
            sb = xs.toString();
            if (sa.equals(sb)) {
                System.out.println(s);
                System.out.println(i);
                return;
            }
            a = new BigInteger(s.toString());
            b = new BigInteger(xs.toString());
            a = a.add(b);
        }

        System.out.println(xs);
        System.out.println(k);

        

        in.close();
        return;
    }
}