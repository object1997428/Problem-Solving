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
typedef long long int ll;

int ans;
vector<vector<int>> info;
int maxA,maxB;
vector<int> pickAB;
int dp[41][121];
int N;
int solve(int cnt, int sumB){
    if(cnt==info.size()){
        // ans=min(ans,sumA);
        return 0;
    }
    
    int& ret=dp[cnt][sumB];
    if(ret!=-1) return ret;

    ret=INT_MAX;
    if(sumB+info[cnt][1]<maxB){
        ret=min(ret,solve(cnt+1,sumB+info[cnt][1]));
    }
    ret=min(ret,solve(cnt+1,sumB)+info[cnt][0]);
    return ret;
}

int simulate(){
    int sumA=0,sumB=0;
    for(int i=0;i<info.size();i++){
        if(pickAB[i]==0) sumB+=info[i][1];
        else sumA+=info[i][0];
        
        if(sumA>=maxA||sumB>=maxB) return INT_MAX;
    }
    return sumA;
}

int solution(vector<vector<int>> _info, int n, int m) {
    info=_info, maxA=n,maxB=m;
    ans=INT_MAX;
    N=info.size(); 
    memset(dp,-1,sizeof(dp));

    //solve
    int answer = solve(0,0);
    if(answer>=maxA) answer=-1;
    return answer;
}