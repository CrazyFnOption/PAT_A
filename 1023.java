/*
    这道题算是一道简单题  主要是因为懂java的缘故吧 所以后面需要将java大作业实现一下
    
    要不然java基本上都忘记了
*/
import java.util.Scanner;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        BigInteger a,b;
        a = in.nextBigInteger();
        b = a.multiply(new BigInteger("2"));
        String ta = a.toString();
        String tb = b.toString();
        if (tb.length() != ta.length()) {
            System.out.println("No");
            System.out.println(tb);
            return;
        }
        int len = tb.length();
        int []tta = new int [10];
        int []ttb = new int [10];

        for (int i = 0; i < len; i++) {
            char ch1 = ta.charAt(i);
            int aa = (int) ch1 - '0';
            tta[aa]++;
            char ch2 = tb.charAt(i);
            int bb = (int) ch2 - '0';
            ttb[bb]++;
        }

        for (int i = 0; i < 10; i++) {
            if (tta[i] != ttb[i]) {
                System.out.println("No");
                System.out.println(tb);
                return;
            }
        }

        System.out.println("Yes");
        System.out.println(tb);


        in.close();
        return;
    }
}