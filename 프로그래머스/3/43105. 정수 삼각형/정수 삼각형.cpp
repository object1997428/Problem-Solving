#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <cassert>
#include <cmath>
#include <iostream>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int dp[501][1001];

int solution(vector<vector<int>> triangle) {
    int N=triangle.size();
    
    dp[0][0]=triangle[0][0];
    for(int i=1;i<N;i++){
        for(int j=0;j<triangle[i].size();j++){
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
            if(i-1>=0&&j-1>=0) dp[i][j]=max(dp[i][j],dp[i-1][j-1]);
            
            dp[i][j]+=triangle[i][j];
            // cout<<dp[i][j]<<" ";
        }
        // cout<<endl;
    }
    
    int ans=INT_MIN;
    for(int i=0;i<triangle[N-1].size();i++){
        ans=max(ans,dp[N-1][i]);
    }
    
    
    int answer = ans;
    return answer;
}