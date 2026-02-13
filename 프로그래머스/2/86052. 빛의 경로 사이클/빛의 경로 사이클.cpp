#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cassert>
#include <cmath>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int> pip;
typedef long long ll;

int N,M;
int way[4][2]={{-1,0},{0,1},{1,0},{0,-1}};

int chk[501][501][4];
queue<pip> q1;
vector<string> arr;

int solve(int sy,int sx,int sw){
    while(!q1.empty()) q1.pop();
    
    chk[sy][sx][sw]=1;
    q1.push({{sy,sx},sw});
    while(!q1.empty()){
        int y=q1.front().first.first;
        int x=q1.front().first.second;
        int w=q1.front().second;
        q1.pop();
        
        // cout<<"y: "<<y<<" x: "<<x<<" w: "<<w<<endl;
        
        int ny=(y+way[w][0]+N)%N;
        int nx=(x+way[w][1]+M)%M;
        int nw=w;
        if(arr[ny][nx]=='L') nw=(w+4-1)%4;
        else if(arr[ny][nx]=='R') nw=(w+4+1)%4;
        
        // if(y==1&&x==0&&w==3){
        //     cout<<" x: "<<x<<" w: "<<w<<" way[w][1]: "<<way[w][1]<<" nx: "<<nx<<" M: "<<M<<endl;
        // }
        
        if(chk[ny][nx][nw]>0) return chk[y][x][w];
        chk[ny][nx][nw]=chk[y][x][w]+1;
        q1.push({{ny,nx},nw});
    }
}

vector<int> solution(vector<string> grid) {
    arr=grid;
    N=grid.size(), M=grid[0].size();
    
    vector<int> answer;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            for(int w=0;w<4;w++){
                if(chk[i][j][w]==0){
                    int ret=solve(i,j,w);
                    
                    answer.push_back(ret);
                }
            }
        }
    }
    sort(answer.begin(),answer.end());
    
    
    return answer;
}