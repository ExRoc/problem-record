import java.util.*;
import java.math.*;

public
class Main {
   public
    static BigInteger getMin(int n) { return BigInteger.TEN.pow(n - 1); }

   public
    static BigInteger getMax(int n) {
        BigInteger ret = getMin(n + 1);
        return ret.subtract(BigInteger.ONE);
    }

   public
    static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        if (n > m) {
            int tmp = m;
            m = n;
            n = tmp;
        }
        if (n == m) {
            System.out.println("0 " + getMax(m).subtract(getMin(n)));
            return;
        }
        System.out.println(getMin(m).subtract(getMax(n)) + " " +
                           getMax(m).subtract(getMin(n)));
    }
}