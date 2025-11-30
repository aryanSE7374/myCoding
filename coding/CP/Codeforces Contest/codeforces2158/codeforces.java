import java.util.*;

public class codeforces {

    static Scanner sc = new Scanner(System.in);

    public static void SOLVE() {
        int n = sc.nextInt();
        int y = sc.nextInt();
        int r = sc.nextInt();

        int ans = 0;

        ans += r;
        ans += (y / 2);
        ans = Math.min(ans, n);

        System.out.println(ans);
    }

    public static void main(String[] args) {
        int t = sc.nextInt();
        while (t-- > 0) {
            SOLVE();
        }
    }
}