import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

import static java.lang.Math.min;

public class Main {

    private static BufferedReader br;
    private static StringTokenizer st;
    private static int N;
    private static int[] chked = new int[1001];
    private static int[][] cost = new int[1001][3];
    private static int[][] dp = new int[1001][3];

    public static void main(String[] args) throws IOException {
        //System.setIn(new FileInputStream("input.txt"));
        br = new BufferedReader(new InputStreamReader(System.in));

        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 3; j++) {
                cost[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        for (int i = 0; i <= N; i++) {
            dp[i][0] = -1;
            dp[i][1] = -1;
            dp[i][2] = -1;
        }
        chked[1]=0;
        int ret = dfs(2, 0)+cost[1][0];
        for (int i = 0; i <= N; i++) {
            chked[i] = -1;
            dp[i][0] = -1;
            dp[i][1] = -1;
            dp[i][2] = -1;
        }
        chked[1]=1;
        ret = Math.min(ret, dfs(2, 1)+cost[1][1]);
        for (int i = 0; i <= N; i++) {
            chked[i] = -1;
            dp[i][0] = -1;
            dp[i][1] = -1;
            dp[i][2] = -1;
        }
        chked[1]=2;
        ret = Math.min(ret, dfs(2, 2)+cost[1][2]);

        System.out.println(ret);
    }

    private static int dfs(int k, int prevC) {
        if (k == N + 1) return 0;
        int ret = dp[k][prevC];
        if (ret != -1) return ret;

        int prev = (k - 1 <= 0) ? k - 1 + N : k - 1;
        int next = (k + 1 > N) ? k + 1 - N : k + 1;

        ret = Integer.MAX_VALUE;
        for (int i = 0; i < 3; i++) {
            if (k == N) {
                if(chked[1]!=i&&prevC!=i){
                    ret = min(ret, dfs(k + 1, i) + cost[k][i]);
                }
            }
            else if (prevC != i) {
                ret = min(ret, dfs(k + 1, i) + cost[k][i]);
            }
        }
        return dp[k][prevC] = ret;
    }


}