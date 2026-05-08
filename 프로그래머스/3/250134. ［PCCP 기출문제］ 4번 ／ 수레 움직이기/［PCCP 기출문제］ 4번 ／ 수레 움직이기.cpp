#include <string>
#include <vector>
#include <string.h>
#include <climits>
#include <cassert>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int,int> pii;

int N,M;
vector<vector<int>> arr;
int rchk[5][5],bchk[5][5];
int rey,rex, bey,bex;
int ans;
int way[4][2]={{-1,0},{0,1},{1,0},{0,-1}};

void solve(int k, int ry,int rx,int by,int bx){
    if(k>=ans) return;
    if(ry==rey&&rx==rex&&by==bey&&bx==bex){
        ans=min(ans,k);
        return;
    }
    
    if(!(ry==rey&&rx==rex)&&!(by==bey&&bx==bex)){
            for(int w=0;w<4;w++){
            //빨강 정하기
            int rny=ry+way[w][0];
            int rnx=rx+way[w][1];
            if(rny>=0&&rnx>=0&&rny<N&&rnx<M&&arr[rny][rnx]!=5&&rchk[rny][rnx]==0){
                rchk[rny][rnx]=1;

                for(int w2=0;w2<4;w2++){
                    //파랑 정하기
                    int bny=by+way[w2][0];
                    int bnx=bx+way[w2][1];
                    if(bny==rny&&bnx==rnx) continue;
                    if(bny==ry&&bnx==rx&&by==rny&&bx==rnx) continue;
                    if(bny>=0&&bnx>=0&&bny<N&&bnx<M&&arr[bny][bnx]!=5&&bchk[bny][bnx]==0){
                        bchk[bny][bnx]=1;
                        solve(k+1, rny, rnx, bny, bnx);
                        bchk[bny][bnx]=0;
                    }
                }

                rchk[rny][rnx]=0;
            }
        }
    }
    else if(ry==rey&&rx==rex){
        for(int w2=0;w2<4;w2++){
            //파랑 정하기
            int bny=by+way[w2][0];
            int bnx=bx+way[w2][1];
            if(bny==ry&&bnx==rx) continue;
            if(bny>=0&&bnx>=0&&bny<N&&bnx<M&&arr[bny][bnx]!=5&&bchk[bny][bnx]==0){
                bchk[bny][bnx]=1;
                solve(k+1, ry, rx, bny, bnx);
                bchk[bny][bnx]=0;
            }
        }
    }
    else if(by==bey&&bx==bex){
        
        for(int w=0;w<4;w++){
            //빨강 정하기
            int rny=ry+way[w][0];
            int rnx=rx+way[w][1];
            if(by==rny&&bx==rnx) continue;
            
            if(rny>=0&&rnx>=0&&rny<N&&rnx<M&&arr[rny][rnx]!=5&&rchk[rny][rnx]==0){
                rchk[rny][rnx]=1;
                solve(k+1, rny, rnx, by, bx);
                rchk[rny][rnx]=0;
            }
        }
    }
    
    
}

int solution(vector<vector<int>> maze) {
    N=maze.size(), M=maze[0].size();
    arr=maze;
    ans=INT_MAX;
    int ry,rx,by,bx;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(maze[i][j]==1) ry=i,rx=j;
            if(maze[i][j]==2) by=i,bx=j;
            if(maze[i][j]==3) rey=i,rex=j;
            if(maze[i][j]==4) bey=i,bex=j;
        }
    }
    rchk[ry][rx]=1;
    bchk[by][bx]=1;
    solve(0,ry,rx,by,bx);
    
    
    int answer = ans;
    if(answer==INT_MAX) answer=0;
    return answer;
}