import java.math.BigInteger;
import java.util.*;

public
class Main {
   public
    static void main(String[] args) {
        BigInteger n;
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextBigInteger();
        scanner.close();
        BigInteger ntmp = n;
        BigInteger d = new BigInteger("5");
        BigInteger zero = BigInteger.ZERO;
        BigInteger cnt5 = zero;
        BigInteger n_2 = n;
        BigInteger one = BigInteger.ONE;
        BigInteger two = one.add(one);
        if (!n.mod(two).equals(zero)) {
            n_2 = n.subtract(one);
        }
        BigInteger five = new BigInteger("5");
        while (ntmp.compareTo(five) >= 0) {
            BigInteger tmp = ntmp.divide(five);
            BigInteger a =
                n_2.subtract(d.add(one).divide(two).multiply(two).subtract(two))
                    .divide(two);
            BigInteger an =
                a.subtract(d.multiply(tmp.add(one).divide(two).subtract(one)));
            cnt5 = cnt5.add(
                a.add(an).multiply(tmp.add(one).divide(two)).divide(two));
            a = n_2.subtract(
                       d.add(d).add(one).divide(two).multiply(two).subtract(
                           two))
                    .divide(two);
            an = a.subtract(d.multiply(tmp.divide(two).subtract(one)));
            cnt5 = cnt5.add(a.add(an).multiply(tmp.divide(two)).divide(two));
            ntmp = tmp;
            d = d.multiply(five);
        }
        BigInteger ten = BigInteger.TEN;
        if (n.mod(two).equals(one) && n.compareTo(five) >= 0) {
            ntmp = n.subtract(five).divide(ten).multiply(ten).add(five);
            while (!ntmp.equals(zero)) {
                cnt5 = cnt5.add(ntmp.divide(five).add(one).divide(two));
                ntmp = ntmp.divide(five);
            }
        }
        System.out.println(cnt5);
    }
}
