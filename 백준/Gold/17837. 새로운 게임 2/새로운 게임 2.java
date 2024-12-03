import java.io.*;
import java.util.StringTokenizer;


public class Main {

    private static BufferedReader br;
    private static StringTokenizer st;
    private static int N,K;
    private static int[][] arr=new int[13][13];
    private static class node{
        int y,x,w;
    }
    private static node[] dot=new node[11];
    private static int[][] arr_bottom=new int[13][13];
    private static int[][] way={{0,0},{0,1},{0,-1},{-1,0},{1,0}};
    private static int[] top=new int[11];
    private static int count;

    public static void main(String[] args) throws IOException {
        //System.setIn(new FileInputStream("input.txt"));
        br=new BufferedReader(new InputStreamReader(System.in));
        st=new StringTokenizer(br.readLine());

        //Init
        N=Integer.parseInt(st.nextToken());
        K=Integer.parseInt(st.nextToken());
        for(int i=0;i<N;i++){
            st=new StringTokenizer(br.readLine());
            for(int j=0;j<N;j++){
                arr[i][j]=Integer.parseInt(st.nextToken());
                arr_bottom[i][j]=-1;
            }
        }
        for(int i=0;i<K;i++){
            st=new StringTokenizer(br.readLine());
            dot[i]=new node();
            dot[i].y=Integer.parseInt(st.nextToken())-1;
            dot[i].x=Integer.parseInt(st.nextToken())-1;
            dot[i].w=Integer.parseInt(st.nextToken());
            arr_bottom[dot[i].y][dot[i].x]=i;
        }
        for(int i=0;i<K;i++){
            top[i]=-1;
        }

        //Solve
        int ans=-1;
        for(int i=1;i<=1000;i++){
            count=i;
            simulate();
            if(isDone()){
                ans=i; break;
            }
        }
        System.out.println(ans);
    }

    private static boolean isDone() {
        for(int i=0;i<K;i++){
            int num=i;
            int y=dot[num].y,x=dot[num].x,w=dot[num].w;
            int depth=countDepth(num,0);
            if(depth>=4){
                return true;
            }
        }
        return false;
    }

    private static void simulate() {
        for(int i=0;i<K;i++){
            //각 말 하나씩 이동시키기
            int num=i;
            int y=dot[num].y,x=dot[num].x,w=dot[num].w;
            int ny=y+way[w][0], nx=x+way[w][1],nw=w;
            if(arr_bottom[y][x]==-1){
                int q=0;
            }

            int course=-1;
            //흰색
            if(ny>=0&&nx>=0&&ny<N&&nx<N&&arr[ny][nx]==0){
                course=0;
                int next_bottom=arr_bottom[ny][nx];
                //다음칸에 말이 있다면, 맨 위에 말 찾기
                if(next_bottom!=-1){
                    int next_top=next_bottom;
                    if(top[next_bottom]!=-1) next_top=getEnd(next_bottom);
                    //맨윗칸에 num 옮기기
                    top[next_top]=num;
                }
                //다음칸이 비어있으면, 다음칸 처음칸=num
                else arr_bottom[ny][nx]=num;
                //이전칸 맨 밑이 num이면 비워주기
                if(arr_bottom[y][x]==num) arr_bottom[y][x]=-1;
                else{
                    if(arr_bottom[y][x]==-1){
                        int q=0;
                    }
                    int findOnegetmeTop=findOnegetmeTop(arr_bottom[y][x],num);
                    top[findOnegetmeTop]=-1;
                }
            }
            else if(ny>=0&&nx>=0&&ny<N&&nx<N&&arr[ny][nx]==1){
                course=1;
                //나부터 맨위까지 뒤집기
                int now_bottom=getEnd(num);
                if(now_bottom==-1){
                    int q=0;
                }
                reverse(num);
                top[num]=-1;

                int next_bottom=arr_bottom[ny][nx];
                //다음칸에 말이 있다면, 맨 위에 말 찾기
                if(next_bottom!=-1){
                    int next_top=next_bottom;
                    if(top[next_bottom]!=-1) next_top=getEnd(next_bottom);
                    //맨윗칸에 now_bottom 옮기기
                    top[next_top]=now_bottom;
                }
                //다음칸이 비어있으면, 다음칸 처음칸=now_bottom
                else arr_bottom[ny][nx]=now_bottom;
                //이전칸 맨 밑이 num이면 비워주기
                if(arr_bottom[y][x]==num) arr_bottom[y][x]=-1;
                else {
                    if(arr_bottom[y][x]==-1){
                        int q=0;
                    }
                    int findOnegetmeTop=findOnegetmeTop(arr_bottom[y][x],num);
                    top[findOnegetmeTop]=-1;
                }
            }
            else {
                course=2;
                nw=reverseWay(w);
                ny=y+way[nw][0];
                nx=x+way[nw][1];
                //반대방향으로 해서 다음칸이 갈 수 있으면
                if(ny>=0&&nx>=0&&ny<N&&nx<N&&arr[ny][nx]!=2){
                    //이동해도 되니까, for문다시 돌아서 이동할 에정
                    i--;
                }
                ny=y;
                nx=x;
                if(arr_bottom[y][x]==-1){
                    int q=0;
                }
            }
            //바뀐 값 dot에 다시 집어넣기
            dot[num].y=ny;
            dot[num].x=nx;
            dot[num].w=nw;

            changeYX(arr_bottom[ny][nx],ny,nx);
            if(isDone()){
                return;
            }
        }
    }

    private static int reverseWay(int w) {
        if(w==1) return 2;
        if(w==2) return 1;
        if(w==3) return 4;
        if(w==4) return 3;
        System.out.println("w가 1~4 외에 발생");
        return 0;
    }
    private static void changeYX(int num,int ny,int nx){
        dot[num].y=ny;
        dot[num].x=nx;
        if(top[num]==-1) return;

        changeYX(top[num],ny,nx);
        return;
    }

    private static int reverse(int x) {
        if(top[x]==-1) return x;
        int b= reverse(top[x]); //내 위를 받아서(b), b의 위를 나(a)로.
        top[b]=x;
        return x;
    }

    private static int getEnd(int x) {
        if(top[x]==-1) return x;
        return getEnd(top[x]);
    }

    private static int findOnegetmeTop(int x,int num){
        if(top[x]==-1) return -1;
        if(top[x]==num) return x;
        return findOnegetmeTop(top[x],num);
    }

    private static int countDepth(int x,int depth) {
        if(top[x]==-1) return 1;
        if(depth>11){
            int q=0;
        }
        return countDepth(top[x],depth+1)+1;
    }




}