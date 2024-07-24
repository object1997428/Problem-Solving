#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <cassert>
#include <cmath>
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> pip;
typedef long long int ll;
#include <unordered_map>
#define endl '\n'

int my,mx;
int N;
int chked[181][181]; 
vector<vector<int>> arr;
priority_queue<pip,vector<pip>,greater<pip>> q;

int bfs(int sy,int sx,int st){
    
    q.push({st,{sy,sx}});
    for(int i=0;i<=180;i++)for(int j=0;j<=180;j++) chked[i][j]=INT_MAX;
    chked[sy][sx]=st;
    
    int ans=INT_MAX;
    while(!q.empty()){
        int y=q.top().second.first;
        int x=q.top().second.second;
        int t=q.top().first;
        q.pop();
        
        if(y>=my&&x>=mx){
            return t;
        }
        
        y=min(y,my);
        x=min(x,mx);
        
        if(t>chked[y][x]) continue;
        
        
        //1.
        int ny=y+1,nx=x,nt=t+1;
         if(y<my&&nt<chked[ny][nx]){
             q.push({nt,{ny,nx}});
             chked[ny][nx]=nt;
        }
        //2.
        ny=y,nx=x+1,nt=t+1;
        if(x<mx&&nt<chked[ny][nx]){
            q.push({nt,{ny,nx}});
            chked[ny][nx]=nt;
        }
        //3.
        for(int i=0;i<N;i++){
            if(arr[i][0]<=y&&arr[i][1]<=x){
                if(arr[i][4]>=arr[i][2]+arr[i][3]) continue;
                ny=y+arr[i][2], nx=x+arr[i][3], nt=t+arr[i][4];
                
                if(nt<chked[ny][nx]&&nt<=300){
                    q.push({nt,{ny,nx}});
                    chked[ny][nx]=nt;
                }
            }
        }
    }
    
    return ans;
}

int solution(int alp, int cop, vector<vector<int>> problems) {
    arr=problems;
    N=arr.size();
    my=0,mx=0;
    for(int i=0;i<N;i++){
        my=max(my,arr[i][0]);
        mx=max(mx,arr[i][1]);
    }
    
    int ret=bfs(alp,cop,0);
    return ret;
}