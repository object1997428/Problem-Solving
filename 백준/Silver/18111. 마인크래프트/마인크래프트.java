import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br;
    private static StringTokenizer st;
    private static int[][] arr = new int[501][501];
    private static int[][] arrCopy = new int[501][501];
    private static int minH, maxH, N, M, B;

    public static void main(String[] args) throws Exception {
        //System.setIn(new FileInputStream("input.txt"));
        br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine());
//        System.out.println(Math.log(500));
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                minH = Math.min(minH, arr[i][j]);
                maxH = Math.max(maxH, arr[i][j]);
            }
        }

        int minT = Integer.MAX_VALUE, ansH = Integer.MIN_VALUE;
        for (int i = maxH; i >= minH; i--) {
            int t = simulate(i);
            if (t < minT) {
                minT = t;
                ansH = i;
            } else if (t == maxH) {
                ansH = Math.max(ansH, i);
            }
        }
        System.out.println(minT + " " + ansH);
    }

    private static int simulate(int k) {//땅을 k개로 똑같이 만들기, 안되면 -1
        int block = B, time = 0;
        for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) arrCopy[i][j] = arr[i][j];

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) {
                if (arrCopy[i][j] > k) {
                    int plus = arrCopy[i][j] - k; //빼야하는 h
                    time += plus * 2;
                    block += plus;
                    arrCopy[i][j] -= plus;
                } else if (arrCopy[i][j] < k) {
                    int plus = k - arrCopy[i][j]; //붙여줘야하는 h
                    time += plus;
                    block -= plus;
                    arrCopy[i][j] += plus;
                }
            }
        if (block < 0) return Integer.MAX_VALUE;
        return time;
    }
}