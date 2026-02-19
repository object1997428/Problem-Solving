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

#define MAX 5000
#define MOD 1000000007

ll dp[MAX+1];

ll solve(int k){
    if(k==2) return 3;
    if(k<=MAX){
        if(dp[k]!=-1) return dp[k];
    }
    
    ll ret=(solve(k-2)*3+2)%MOD;
    for(int i=4;i<k;i+=2){
        ret+=(solve(k-i)*2)%MOD;
        ret=ret%MOD;
    }
    
    if(k<=MAX) dp[k]=ret;
    
    return ret;
}


int solution(int n) {
    memset(dp,-1,sizeof(dp));

    return solve(n);
}