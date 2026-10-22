#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <climits>
#include <cassert>
#include <cmath>
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;

ll N,M;
priority_queue<pii,vector<pii>,greater<>> q1;
ll maxT;
vector<int> times;

//k시간 안에 N개 소화가능한지
bool isValid(ll k){
    ll sum=0;
    for(int i=0;i<M;i++){
        sum+=k/times[i];
        if(sum>=N) return true;
    }
    return false;
}

ll solve(){
    ll l=0, r=times[0]*N;
    ll ret=r;
    while(l<=r){
        ll m=(l+r)/2;
        if(isValid(m)){
            r=m-1;
            ret=min(ret,m);
        }
        else l=m+1;
    }
    return ret;
}

long long solution(int n, vector<int> _times) {
    times=_times;
    N=n, M=times.size();
    sort(times.begin(),times.end());
    
    
    
    
    long long answer = solve();
    return answer;
}