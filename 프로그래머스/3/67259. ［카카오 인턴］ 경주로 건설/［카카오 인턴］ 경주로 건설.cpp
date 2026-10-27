#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <climits>
#include <cassert>
#include <cmath>
#include <iostream>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,pii> pp;
typedef long long ll;

int N;
int visited[26][26][2];
priority_queue<pp,vector<pp>,greater<>> q;




int way[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
vector<vector<int>> board;

int solve(){
    
    for(int i=0;i<26;i++)for(int j=0;j<26;j++)for(int k=0;k<2;k++) visited[i][j][k]=INT_MAX;
    
    visited[0][0][0]=visited[0][0][1]=0;
    if(board[0][1]==0){
        visited[0][1][1]=100;
        q.push({{100,1},{0,1}});
    }
    if(board[1][0]==0){
        visited[1][0][0]=100;
        q.push({{100,0},{1,0}});
    }

    
    while(!q.empty()){
        int y=q.top().second.first;
        int x=q.top().second.second;
        int k=q.top().first.second;
        int w=q.top().first.first;
        q.pop();
        
        if(y==N-1&&x==N-1) return w;
        
        for(int w=0;w<4;w++){
            int ny=y+way[w][0];
            int nx=x+way[w][1];
            if(ny<0||nx<0||ny>=N||nx>=N||board[ny][nx]==1) continue;
            
            
            if(k==0){
                if(w==0||w==2){//같은 방향 세로
                    if(visited[ny][nx][0]>visited[y][x][k]+100){

                        visited[ny][nx][0]=visited[y][x][k]+100;
                        q.push({{visited[y][x][k]+100,0},{ny,nx}});
                        // cout<<"ny: "<<ny<<" nx: "<<nx<<" y: "<<y<<" x: "<<x<<"직진"<<" w: "<<visited[ny][nx][0]<<endl;
                    }
                   
                }
                else {//다른 방향 가로
                    
                    if(visited[ny][nx][1]>visited[y][x][k]+600){

                        visited[ny][nx][1]=visited[y][x][k]+600;
                        q.push({{visited[y][x][k]+600,1},{ny,nx}});
                        // cout<<"ny: "<<ny<<" nx: "<<nx<<" y: "<<y<<" x: "<<x<<"수직"<<" w: "<<visited[ny][nx][1]<<endl;
                    }
                    
                }
            }
            else { //k==1: 가로였음
                if(w==0||w==2){//다른 방향: 세로
                    
                    if(visited[ny][nx][0]>visited[y][x][k]+600){
                        
                        visited[ny][nx][0]=visited[y][x][k]+600;
                        q.push({{visited[y][x][k]+600,0},{ny,nx}});
                        
                        // cout<<"ny: "<<ny<<" nx: "<<nx<<" y: "<<y<<" x: "<<x<<"수직"<<" w: "<<visited[ny][nx][1]<<endl;
                    }
                    
                }
                else {//같은 방향: 가로
                    if(visited[ny][nx][1]>visited[y][x][k]+100){
                        
                        visited[ny][nx][1]=visited[y][x][k]+100;
                        q.push({{visited[y][x][k]+100,1},{ny,nx}});
                        // cout<<"ny: "<<ny<<" nx: "<<nx<<" y: "<<y<<" x: "<<x<<"직진"<<" w: "<<visited[ny][nx][0]<<endl;
                    }
                    
                }
            }
            
        }
    }
    
}



int solution(vector<vector<int>> _board) {
    board=_board;
    N=board.size();
    solve();
    int ret1=visited[N-1][N-1][0];
    int ret2=visited[N-1][N-1][1];
    
    cout<<"ret1: "<<ret1<<" ret2: "<<ret2<<endl;
    
    int answer = min(ret1,ret2);
    return answer;
}