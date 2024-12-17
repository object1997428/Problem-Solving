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
int N;
int ans,number;

vector<ll> solve(int cnt){
    if(cnt<1){
        assert(0);
        return {};
    }
    if(cnt>8){
        assert(0);
    }
    if(cnt==1) return {N};
    
    if(!dp[cnt].empty()) return dp[cnt];
    
    for(int i=1;i<=cnt-1;i++){
        if(cnt-i<1||cnt-i>8||i>8||i<1) continue;
        auto prev=solve(cnt-i);
        auto next=solve(i);
        for(int j=0;j<prev.size();j++){
            for(int k=0;k<next.size();k++){
                ll p=prev[j];
                ll n=next[k];
                //더하기
                dp[cnt].push_back(p+n);
                //빼기
                dp[cnt].push_back(p-n);
                
                //나누기
                if(n!=0){
                    ll dvd=(ll)floor(p/n);
                    dp[cnt].push_back(dvd);
                    // if(dvd==number){
                    //      ans=min(ans,cnt);
                    // }
                }
                
                //곱하기
                dp[cnt].push_back(p*n);
                // if(p+n==number||p-n==number||p*n==number){
                //     ans=min(ans,cnt);
                // }
            }
        }
    }
    //555넣기
    ll tmp=N;
    for(int i=0;i<cnt-1;i++){
        tmp=tmp*10+N;
    }
    // cout<<"N: "<<N<<" cnt: "<<cnt<<" tmp: "<<tmp<<endl;
    dp[cnt].push_back(tmp);
    // if(tmp==number){
    //     ans=cnt;
    // }
    //중복값 빼기
    sort(dp[cnt].begin(),dp[cnt].end());
    dp[cnt].erase(unique(dp[cnt].begin(),dp[cnt].end()),dp[cnt].end());
    // cout<<"cnt: "<<cnt<<endl;
    // for(int i=0;i<dp[cnt].size();i++){
    //     cout<<"-----dp[cnt]: "<<dp[cnt][i]<<endl;
    // }
    return dp[cnt];
}

int solution(int n, int _number) {
    N=n;number=_number;
    ans=INT_MAX;
    if(number==n) return 1;
    for(int i=1;i<=8;i++){
        solve(i);
    }
    for(int i=1;i<=8;i++){
        if(find(dp[i].begin(),dp[i].end(),number)!=dp[i].end()){
            ans=i; break;
        }
    }
    
    int answer = ans;
    if(ans==INT_MAX||ans>8) answer=-1;
    return answer;
}