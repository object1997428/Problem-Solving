#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cassert>
#include <cmath>
#include <climits>
#include <iostream>
using namespace std;
typedef long long int ll;

vector<ll> dp[10];
ll N;
vector<ll> solve(int cnt){
    // assert(cnt!=0);
    if(cnt>8) return {};
    if(cnt==1) return {N};
    
    if(!dp[cnt].empty()) return dp[cnt];
    
    //NNNN 만들기
    ll NN_=0;
    for(int i=0;i<cnt;i++) NN_=NN_*10+N;
    dp[cnt].push_back(NN_);
    
    //가능한 숫자들 만들기
    for(int i=1;i<cnt;i++){
        vector<ll> v1=solve(i);
        vector<ll> v2=solve(cnt-i);
        
        for(auto prev: v1){ //i번으로 만들수 있는 숫자
            for(auto next: v2){ //cnt-i번으로 만들 수 있는 숫자
                ll val1=prev+next;
                ll val2=prev-next;
                ll val3=prev*next;
                if(next!=0){
                    ll val4=(ll)floor((double)prev/next);
                    dp[cnt].push_back(val4);
                }

                dp[cnt].push_back(val1);
                dp[cnt].push_back(val2);
                dp[cnt].push_back(val3);
            }
        }
    }
    sort(dp[cnt].begin(),dp[cnt].end());
    dp[cnt].erase(unique(dp[cnt].begin(),dp[cnt].end()),dp[cnt].end());
    
    return dp[cnt];
    
}

int solution(int _N, int number) {
    N=_N;
    if(number==N) return 1;
    
    for(int i=2;i<=8;i++) solve(i);
    
    for(int i=2;i<=8;i++){
        //i번째로 만든 수에 number가 있으면 바로 i리턴
        if(dp[i].empty()) continue;
        for(ll val:dp[i]) if(val==number) return i;
    }
    
    return -1;
}