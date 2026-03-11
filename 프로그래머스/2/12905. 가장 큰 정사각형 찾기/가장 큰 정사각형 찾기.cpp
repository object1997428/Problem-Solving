#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <climits>
#include <cassert>
#include <cmath>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define endl '\n'

int dp[1001][1001];
int N,M;

int solution(vector<vector<int>> board)
{
    N=board.size(), M=board[0].size();
    memset(dp,0,sizeof(dp));
    
    int ans=0;
    for(int i=0;i<N;i++) dp[i][0]=board[i][0], ans=max(ans,dp[i][0]);
    for(int i=0;i<M;i++) dp[0][i]=board[0][i], ans=max(ans,dp[0][i]);
    
    for(int i=1;i<N;i++){
        for(int j=1;j<M;j++){
            if(board[i][j]==1) {
                // if(i==1&&j==1){
                //     cout<<dp[i-1][j-1]<<endl;
                // }
                dp[i][j]=min(dp[i-1][j],dp[i][j-1]);
                dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
                dp[i][j]+=board[i][j];
                ans=max(ans,dp[i][j]);
            }
            
            // cout<<dp[i][j]<<" ";
        }
        // cout<<endl;
    }
    

    return ans*ans;
}