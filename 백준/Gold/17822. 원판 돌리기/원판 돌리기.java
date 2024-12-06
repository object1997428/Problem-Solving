import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;


public class Main {

    private static BufferedReader br;
    private static StringTokenizer st;
    private static int N,M,T;
    private static int[][][] arr;
    private static int[][] chk;
    private static int cnt;

    public static void main(String[] args) throws IOException {
        //System.setIn(new FileInputStream("input.txt"));
        br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine());

        //input
        N=Integer.parseInt(st.nextToken());
        M=Integer.parseInt(st.nextToken());
        T=Integer.parseInt(st.nextToken());
        cnt=N*M;
        arr=new int[N+1][M+1][2];
        chk=new int[N+1][M+1];

        for(int i=1;i<=N;i++){
            st = new StringTokenizer(br.readLine());
            for(int j=0;j<M;j++){
                arr[i][j][0]=Integer.parseInt(st.nextToken());
                arr[i][j][1]=1;
                chk[i][j]=0;
            }
        }

        //solve
        for(int i=0;i<T;i++){
            st = new StringTokenizer(br.readLine());
            int x=Integer.parseInt(st.nextToken());
            int d=Integer.parseInt(st.nextToken());
            int k=Integer.parseInt(st.nextToken());
            rotate(x,d,k);
        }

        //output ans
        int sum=0;
        for(int i=1;i<=N;i++)for(int j=0;j<M;j++) if(arr[i][j][1]!=-1) sum+=arr[i][j][0];
        System.out.println(sum);

    }

    private static void rotate(int x, int d, int k) {
        //roate
        for(int i=1;i*x<=N;i++){
            int row=i*x;
            if(d==0){//시계
                for(int r=0;r<k%M;r++){
                    int[] tmp=arr[row][M-1];
                    for(int j=M-2;j>=0;j--){
                        arr[row][j+1]=arr[row][j];
                    }
                    arr[row][0]=tmp;
                }
            }
            else{
                for(int r=0;r<k%M;r++){
                    int[] tmp=arr[row][0];
                    for(int j=1;j<M;j++){
                        arr[row][j-1]=arr[row][j];
                    }
                    arr[row][M-1]=tmp;
                }
            }

        }
        if(cnt<=0) return;

        //인접하면서 수가 같은 것들 모두 찾기
        for(int i=0;i<=N;i++)for(int j=0;j<M;j++) chk[i][j]=0;
        int count=0;
        for(int i=1;i<=N;i++){
            for(int j=0;j<M;j++){
                if(arr[i][j][1]==-1) continue;
                //살아있으면
                int py=(j-1)>=0?j-1:j-1+M;
                int ny=(j+1)<M?j+1:j+1-M;
                if(arr[i][py][1]!=-1&&arr[i][j][0]==arr[i][py][0]){
                    chk[i][j]=1; chk[i][py]=1;
                }
                if(arr[i][ny][1]!=-1&&arr[i][j][0]==arr[i][ny][0]){
                    chk[i][j]=1; chk[i][ny]=1;
                }
                if(i-1>=0&&arr[i-1][j][1]!=-1&&arr[i][j][0]==arr[i-1][j][0]){
                    chk[i][j]=1; chk[i-1][j]=1;
                }
                if(i+1<=N&&arr[i+1][j][1]!=-1&&arr[i][j][0]==arr[i+1][j][0]){
                    chk[i][j]=1; chk[i+1][j]=1;
                }
            }
        }
        //있으면-> 지우기
        for(int i=1;i<=N;i++)for(int j=0;j<M;j++){
            if(chk[i][j]==1){
                if(arr[i][j][1]==-1){
                    int q=0;
                    System.out.println("죽은게 또 죽음");
                }
                count++;
                arr[i][j][0]=-1; arr[i][j][1]=-1;
                cnt--;
            }
        }

        if(count<=0){
            //평균 구하기
            int sum=0;
            for(int i=1;i<=N;i++)for(int j=0;j<M;j++) if(arr[i][j][1]!=-1) sum+=arr[i][j][0];

            //큰수-1, 작은수+1
            for(int i=1;i<=N;i++)for(int j=0;j<M;j++) {
                if (arr[i][j][1] != -1){
                    if(arr[i][j][0]*cnt>sum) arr[i][j][0]--;
                    else if(arr[i][j][0]*cnt<sum) arr[i][j][0]++;
                }

            }
        }
    }


}