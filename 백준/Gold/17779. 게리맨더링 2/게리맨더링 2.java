import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

import static java.lang.Math.min;
import static java.util.Collections.max;

public class Main {

    private static BufferedReader br;
    private static StringTokenizer st;
    private static int N;
    private static int[][] cnt=new int[21][21];
    private static int[][] arr=new int[21][21];
    private static int ans=Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        //System.setIn(new FileInputStream("input.txt"));
        br=new BufferedReader(new InputStreamReader(System.in));
        st=new StringTokenizer(br.readLine());
        N=Integer.parseInt(st.nextToken());


        for(int i=1;i<=N;i++){
            st=new StringTokenizer(br.readLine());
            for(int j=1;j<=N;j++){
                cnt[i][j]=Integer.parseInt(st.nextToken());
            }
        }
//        System.out.println(N);
//        printArr(cnt);

        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                int x=i,y=j;
                //d1,d2
                for(int d1=1;d1<=N;d1++){
                    for(int d2=1;d2<=N;d2++){
                        int maxX=x+d1+d2;
                        int minY=y-d1,maxY=y+d2;
                        if(maxX<=N&&minY>=1&&maxY<=N){
                            simulate(x,y,d1,d2);
                        }
                    }
                }
            }
        }
        System.out.println(ans);


    }

    private static void simulate(int x, int y, int d1, int d2) {
        //초기화
        for(int i=0;i<=N;i++)for(int j=0;j<=N;j++){
            arr[i][j]=0;
        }

        //경계선
        for(int i=0;i<=d1;i++){
            for(int j=0;j<=d2;j++){
                arr[x+i][y-i]=5;
                arr[x+j][y+j]=5;
                arr[x+d1+j][y-d1+j]=5;
                arr[x+d2+i][y+d2-i]=5;
            }
        }

        //1구역
        for(int i=1;i<x+d1;i++){
            for(int j=1;j<=y;j++){
                if(arr[i][j]!=0) break;
                arr[i][j]=1;
            }
        }
        //2구역
        for(int i=1;i<=x+d2;i++){
            for(int j=N;j>y;j--){
                if(arr[i][j]!=0) break;
                arr[i][j]=2;
            }
        }
        //3구역
        for(int i=x+d1;i<=N;i++){
            for(int j=1;j<y-d1+d2;j++){
                if(arr[i][j]!=0) break;
                arr[i][j]=3;
            }
        }
        //4구역
        for(int i=x+d2+1;i<=N;i++){
            for(int j=N;j>=y-d1+d2;j--){
                if(arr[i][j]!=0) break;
                arr[i][j]=4;
            }
        }
        //구역 정산
        int[] sum={0,0,0,0,0,0};
        int maxSum=Integer.MIN_VALUE, minSum=Integer.MAX_VALUE;
        for(int i=1;i<=N;i++)for(int j=1;j<=N;j++){
            int num=arr[i][j];
            if(num==0) num=5;
            if(arr[i][j]>5){
                System.out.println(arr[i][j]);
                int q=0;
            }
            sum[num]+=cnt[i][j];
        }
        for(int i=1;i<=5;i++){
            if(sum[i]==0) return;
            maxSum=Integer.max(maxSum,sum[i]);
            minSum=Integer.min(minSum,sum[i]);
        }
        ans=min(ans,maxSum-minSum);
    }


    static void printArr(int[][] arrInp){
        for(int i=0;i<N;i++){
            System.out.println(Arrays.toString(arrInp[i]));
        }
    }


}