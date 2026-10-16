#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <climits>
#include <cassert>
#include <cmath>
#include <iostream>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int N;
vector<int> sequence;
ll dp[500001][2]; //[0]: *-1, [1]: *1

ll solve(int cnt, int k){
    if(cnt==N){
        return 0;
    }
    
    ll& ret=dp[cnt][k];
    if(ret!=-1) return ret;
    
    int g=(k==0)?-1:1;
    
    ret=solve(cnt+1,(k+1)%2)+sequence[cnt]*g;
    ret=max(ret,0LL);
    return ret;
}


long long solution(vector<int> _sequence) {
    sequence=_sequence;
    memset(dp,-1,sizeof(dp));
    N=sequence.size();
    
    ll ret1=solve(0,1);
    ll ret2=solve(0,0);
    // cout<<"ret1: "<<ret1<<" ret2: "<<ret2<<endl;
    
    ll ans=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<2;j++){
            ans=max(ans,dp[i][j]);
        }
    }
    

    return ans;
}