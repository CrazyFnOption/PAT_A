import java.util.Scanner;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner (System.in);
        int n = in.nextInt();
        BigInteger a,b,c;
        int Case = 1;
        for (int i = 0; i < n; i++) {
            a = in.nextBigInteger();
            b = in.nextBigInteger();
            c = in.nextBigInteger();

            a = a.add(b);
            int flag = a.compareTo(c);
            System.out.printf("Case #" + Case++ + ": ");
            if (flag == 1) System.out.printf("true\n");
            else System.out.printf("false\n");

        }

        in.close();
        return ;
    }
}