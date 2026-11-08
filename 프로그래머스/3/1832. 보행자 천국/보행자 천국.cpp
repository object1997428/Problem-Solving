#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cassert>
#include <cmath>
#include <string>
#include <string.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int MOD = 20170805;
int dp[501][501][2];
vector<vector<int>> arr;
int N,M;

int way[2][2]={{0,1},{1,0}};

int solve(int y,int x,int pw){
    if(y>N-1||x>M-1) return 0;
    if(y==N-1&&x==M-1){
        return 1;
    }
    
    int& ret=dp[y][x][pw];
    if(ret!=-1) return ret;
    
    ret=0;
    // cout<<"y: "<<y<<" x: "<<x<<" pw: "<<pw<<endl;
    
    if(arr[y][x]==2){
        int ny=y+way[pw][0];
        int nx=x+way[pw][1];
        if(ny<0||nx<0||ny>=N||nx>=M||arr[ny][nx]==1){
            return ret=0;
        }
        ret=(solve(ny,nx,pw)+ret)%MOD;
        return ret;
    }
    
    for(int w=0;w<2;w++){
        int ny=y+way[w][0];
        int nx=x+way[w][1];
        if(ny<0||nx<0||ny>=N||nx>=M) continue;
        
        if(arr[ny][nx]==1) continue;
        else if(arr[ny][nx]==0||arr[ny][nx]==2){
            ret=(solve(ny,nx,w)+ret)%MOD;
        }
    }
    
    ret=ret%MOD;
    return ret;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    arr=city_map;
    N=arr.size(), M=arr[0].size();
    memset(dp,-1,sizeof(dp));
    MOD = 20170805;
    
    int ret1,ret2;
    ret1=ret2=0;
    if(arr[0][1]!=1) ret1=solve(0,1,0);
    if(arr[1][0]!=1) ret2=solve(1,0,1);
    
    cout<<"ret1: "<<ret1<<" ret2: "<<ret2<<endl;
    int answer = (ret1+ret2)%MOD;
    return answer;
}