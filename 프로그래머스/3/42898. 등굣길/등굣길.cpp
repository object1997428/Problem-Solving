#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cmath>
#include <cassert>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> pip;
typedef long long ll;
#define MOD 1000000007

queue<pii> q;
ll cnt[101][101];
int chked[101][101];
int way[2][2]={{0,1},{1,0}};
int N,M;
int arr[101][101];

ll solve(int sy,int sx){
    q.push({sy,sx});
    chked[sy][sx]=1;
    cnt[sy][sx]=1;
    
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        // cout<<"y: "<<y<<" x: "<<x<<" cnt[y][x]: "<<cnt[y][x]<<endl;
        
        for(int w=0;w<2;w++){
            int ny=y+way[w][0];
            int nx=x+way[w][1];
  
            if(ny>=0&&nx>=0&&ny<N&&nx<M&&arr[ny][nx]==0){
                cnt[ny][nx]=(cnt[ny][nx]+cnt[y][x])%MOD;
                
                if(chked[ny][nx]==0){
                    chked[ny][nx]=1;
                    q.push({ny,nx});
                }
            }
        }
    }
    return cnt[N-1][M-1];
}

int solution(int m, int n, vector<vector<int>> puddles) {
    N=n, M=m;
    for(auto yx:puddles){
        int y=yx[1]-1, x=yx[0]-1;
        arr[y][x]=1;
    }
    memset(chked,0,sizeof(chked));
    
    ll ret=solve(0,0);
    int answer = ret;
    return answer;
}