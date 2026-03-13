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

int N,M;
int dp[1001][1001];

int solution(vector<vector<int>> board)
{
    N=board.size(), M=board[0].size();
    
    int ans=0;
    for(int i=0;i<N;i++) dp[i][0]=board[i][0], ans=max(ans, board[i][0]);
    for(int i=0;i<M;i++) dp[0][i]=board[0][i], ans=max(ans, board[0][i]);
    
    for(int i=1;i<N;i++)
        {for(int j=1;j<M;j++){
            if(board[i][j]==1){
                // if(i==1&&j==1) cout<<"dp[i-1][j-1]: "<<dp[i-1][j-1]<<endl;
                int x=min(dp[i-1][j],dp[i][j-1]);
                x=min(x,dp[i-1][j-1]);

                dp[i][j]=x+1;
            }
            // cout<<dp[i][j]<<" ";
        }
         // cout<<endl;
    }
    
    for(int i=0;i<N;i++)for(int j=0;j<M;j++) ans=max(ans,dp[i][j]);

    return ans*ans;
}