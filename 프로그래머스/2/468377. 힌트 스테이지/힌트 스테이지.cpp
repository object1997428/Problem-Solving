#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <cassert>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define endl '\n'

int hintCnt[17];
int N,K;
vector<vector<int>> cost, hint;
int ans;

void solve(int cnt, int sum){
    if(ans<=sum) return;
    if(cnt==N) {
        ans=min(ans,sum);
        return;
    }
    
    //힌트권 구매X
    int hc=min(hintCnt[cnt],N-1);
    int plus=cost[cnt][hc];
    solve(cnt+1,sum+plus);
    
    //힌트권 구매X
    if(cnt<N-1){
        int c=hint[cnt][0];
        for(int i=0;i<K;i++){
            int s=hint[cnt][i+1]-1;
            hintCnt[s]++;
        }
        
        solve(cnt+1,sum+plus+c);
        
        for(int i=0;i<K;i++){
            int s=hint[cnt][i+1]-1;
            hintCnt[s]--;
        }
    }
}

int solution(vector<vector<int>> _cost, vector<vector<int>> _hint) {
    cost=_cost; hint=_hint;
    N=cost.size(); K=_hint[0].size()-1;
    ans=INT_MAX;
    cout<<"N: "<<N<<endl;
    cout<<"_hint.size(): "<<_hint.size()<<endl;
    
    solve(0,0);
    
    int answer = ans;
    return answer;
}