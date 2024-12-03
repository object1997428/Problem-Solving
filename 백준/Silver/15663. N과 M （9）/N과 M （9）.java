import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;


public class Main {

    private static BufferedReader br;
    private static StringTokenizer st;
    private static int N,M;
    private static int[] arr;
    private static int[] check;
    private static ArrayList<Integer> list=new ArrayList<>();

    public static void main(String[] args) throws IOException {
        //System.setIn(new FileInputStream("input.txt"));
        br=new BufferedReader(new InputStreamReader(System.in));
        st=new StringTokenizer(br.readLine());

        //input
        N=Integer.parseInt(st.nextToken());
        M=Integer.parseInt(st.nextToken());
        arr=new int[N];
        check=new int[N];
        st=new StringTokenizer(br.readLine());
        for(int i=0;i<N;i++){
            arr[i]=Integer.parseInt(st.nextToken());
        }
        //init
        Arrays.sort(arr);


        //solve
        solve(0);
    }

    static void solve(int cnt){
        if(cnt==M){
            for(int i=0;i<list.size();i++){
                System.out.print(list.get(i)+" ");
            }
            System.out.println();
            return;
        }
        for(int i=0;i<N;i++){
            if(i>0&&arr[i-1]==arr[i]&&check[i-1]==0) continue;
            if(check[i]==0){
                check[i]=1;
                list.add(arr[i]);
                solve(cnt+1);
                if(!list.isEmpty()) list.remove(list.size()-1);
                check[i]=0;
            }
        }
    }

}