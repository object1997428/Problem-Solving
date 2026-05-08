#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cassert>
#include <cmath>
#include <string>
#include <string.h>
using namespace std;

int dp[100001][4];
int N;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    N=land.size();
    for(int i=0;i<4;i++){
        dp[N-1][i]=land[N-1][i];
    }
    for(int i=N-2;i>=0;i--){
        for(int j=0;j<4;j++){
            // i층에서 i+1~N층까지 얻을 수 있는 최고점 + 현재 i층 얻기
            for(int k=0;k<4;k++){
                if(j==k) continue;
                dp[i][j]=max(dp[i][j], dp[i+1][k]);
            }
            dp[i][j]+=land[i][j];
            // cout<<dp[i][j]<<" ";
        }
        // cout<<endl;
    }
    int ans=0;
    for(int i=0;i<4;i++){
        ans=max(ans, dp[0][i]);
    }
    

    return ans;
}