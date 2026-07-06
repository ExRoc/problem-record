import java.math.BigInteger;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        List<BigInteger> ans = new ArrayList<BigInteger>();
        ans.add(BigInteger.valueOf(4));
        ans.add(BigInteger.valueOf(14));
        for (int i = 2; i < 100; ++i) {
            ans.add(ans.get(i - 1).multiply(ans.get(0)).subtract(ans.get(i - 2)));
        }

        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int cas = 0; cas < T; ++cas) {
            BigInteger N = in.nextBigInteger();
            int low = -1;
            int high = 99;
            while (high - low > 1) {
                int mid = (high + low) >> 1;
                if (ans.get(mid).compareTo(N) >= 0) {
                    high = mid;
                } else {
                    low = mid;
                }
            }
            System.out.println(ans.get(high));
        }
    }
}