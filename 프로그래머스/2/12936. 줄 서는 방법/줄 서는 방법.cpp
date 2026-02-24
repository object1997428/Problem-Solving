#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <climits>
#include <cassert>
#include <cmath>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define endl '\n'

int N;
ll fac[21];
int chked[21];
vector<int> v1;
vector<int> answer;

void solve(int cnt, ll k){
    if(cnt==N){
        // cout<<"k: "<<k<<endl;
        answer=v1;
        return;
    }
    
    if(!answer.empty()) return;
    
    // cout<<"--cnt: "<<cnt<<" k: "<<k<<" N-cnt-1: "<<N-cnt-1<<endl;
    for(int i=1;i<=N;i++){
        if(chked[i]==1) continue;
        
        ll plus=fac[N-cnt-1];
        if(k>1&&k>plus) {
            k-=plus; continue;
        }
        else{
            // cout<<"cnt: "<<cnt<<" i: "<<i<<endl;
            chked[i]=1;
            v1.push_back(i);
            solve(cnt+1,k);
            if(!answer.empty()) return;
            chked[i]=0;
            v1.pop_back();
        }
    }
}

vector<int> solution(int n, long long k) {
    N=n;
    
    //미리 팩토리얼 계산해놓기
    fac[1]=1;
    for(int i=2;i<=n;i++){
        fac[i]=fac[i-1]*i;
    }
    
    //k번째 수열 구하기
    solve(0,k);
    
    return answer;
}