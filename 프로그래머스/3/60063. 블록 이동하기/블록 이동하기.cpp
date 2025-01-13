#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <climits>
#include <cmath>
#include <cassert>
#include <iostream>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,pii> pp;

int N;
int arr[101][101];

int chk[101][101][2];
int way[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
typedef struct node{
    int y,x,w;
}node;
queue<node> q;

int ans;

int bfs(int sy,int sx,int sw){//w=0: 오른쪽, w=1: 아래쪽
    chk[sy][sx][sw]=1;
    q.push({sy,sx,sw});
    int count=0;
    while(!q.empty()){
        int y=q.front().y;
        int x=q.front().x;
        int w=q.front().w;
        q.pop();
        
        int y1=y,x1=x;
        int y2,x2;
        if(w==0) y2=y,x2=x+1;
        else y2=y+1,x2=x;
        
        
        if(y1==N-1&&x1==N-1){
            ans=min(ans,chk[y][x][w]);
        } 
        if(y2==N-1&&x2==N-1){
            ans=min(ans,chk[y][x][w]);
        }
        
        // cout<<"y: "<<y<<" x: "<<x<<" w: "<<w<<" chk[y][x][w]: "<<chk[y][x][w]<<endl;
        
        //그냥 그대로 동서남북
        for(int i=0;i<4;i++){
            int ny1=y1+way[i][0];
            int nx1=x1+way[i][1];
            int ny2=y2+way[i][0];
            int nx2=x2+way[i][1];
            // cout<<"ny1: "<<ny1<<" nx1: "<<nx1<<" ny2: "<<ny2<<" nx2: "<<nx2<<endl;
            if(ny1>=0&&nx1>=0&&ny1<N&&nx1<N&&ny2>=0&&nx2>=0&&ny2<N&&nx2<N&&arr[ny1][nx1]==0&&arr[ny2][nx2]==0&&chk[ny1][nx1][w]>chk[y][x][w]+1){
                // cout<<"1"<<endl;
                chk[ny1][nx1][w]=chk[y][x][w]+1;
                q.push({ny1,nx1,w});
                // if(ny1==0&&nx1==1&&w==0){
                //     cout<<"chk[ny1][nx1][w]: "<<chk[ny1][nx1][w]<<endl;
                // }
            }
        }
        //90도 회전
        if(w==0){//가로
            if(y2-1>=0&&x2-1>=0&&arr[y2-1][x2]==0&&arr[y2-1][x2-1]==0&&chk[y2-1][x2-1][1]>chk[y][x][w]+1){
                // cout<<"2"<<endl;
                chk[y2-1][x2-1][1]=chk[y][x][w]+1;
                q.push({y2-1,x2-1,1});
            }
            if(y1-1>=0&&x1+1<N&&arr[y1-1][x]==0&&arr[y1-1][x1+1]==0&&chk[y1-1][x1+1][1]>chk[y][x][w]+1){
                // cout<<"3"<<endl;
                chk[y1-1][x1+1][1]=chk[y][x][w]+1;
                q.push({y1-1,x1+1,1});
            }
            if(y1+1<N&&arr[y1+1][x1]==0&&arr[y1+1][x1+1]==0&&chk[y2][x2][1]>chk[y][x][w]+1){
                // cout<<"4"<<endl;
                chk[y2][x2][1]=chk[y][x][w]+1;
                q.push({y2,x2,1});
            }
            if(y2+1<N&&x2-1>=0&&arr[y2+1][x2]==0&&arr[y2+1][x2-1]==0&&chk[y1][x1][1]>chk[y][x][w]+1){
                // cout<<"5"<<endl;
                chk[y1][x1][1]=chk[y][x][w]+1;
                q.push({y1,x1,1});
            }
        }
        else{//세로
            if(x1+1<N&&y1+1<N&&arr[y1][x1+1]==0&&arr[y1+1][x1+1]==0&&chk[y2][x2][0]>chk[y][x][w]+1){
                chk[y2][x2][0]=chk[y][x][w]+1;
                q.push({y2,x2,0});
            }
            if(x1-1>=0&&y1+1<N&&arr[y1][x1-1]==0&&arr[y1+1][x1-1]==0&&chk[y1+1][x1-1][0]>chk[y][x][w]+1){
                chk[y1+1][x1-1][0]=chk[y][x][w]+1;
                q.push({y1+1,x1-1,0});
            }
            if(x2+1<N&&y2-1>=0&&arr[y2][x2+1]==0&&arr[y2-1][x2+1]==0&&chk[y1][x1][0]>chk[y][x][w]+1){
                chk[y1][x1][0]=chk[y][x][w]+1;
                q.push({y1,x1,0});
            }
            if(x2-1>=0&&y2-1>=0&&arr[y2][x2-1]==0&&arr[y2-1][x2-1]==0&&chk[y2-1][x2-1][0]>chk[y][x][w]+1){
                chk[y2-1][x2-1][0]=chk[y][x][w]+1;
                q.push({y2-1,x2-1,0});
            }
        }
        
    }
    return INT_MAX;
}

int solution(vector<vector<int>> board) {
    //init
    N=board.size();
    ans=INT_MAX;
    for(int i=0;i<N;i++)for(int j=0;j<N;j++){
        arr[i][j]=board[i][j];
    }
    for(int i=0;i<N;i++)for(int j=0;j<N;j++)chk[i][j][0]=INT_MAX,chk[i][j][1]=INT_MAX;
    //solve
    bfs(0,0,0);
    
    
    
    int answer = ans-1;
    return answer;
}