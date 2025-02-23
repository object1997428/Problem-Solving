#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cassert>
#include <cmath>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
typedef long long int ll;
queue<pii> q;

int solution(vector<int> players, int m, int k) {
    ll n=0;
    int answer = 0;
    
    //
    for(int i=0;i<24;i++){
        while(!q.empty()&&q.front().first==i){
            // cout<<"i: "<<i<<" time: "<<q.front().first<<" minus: "<<q.front().second<<endl;
            n-=q.front().second;
            q.pop();
        }
        // cout<<"i: "<<i<<" players[i]: "<<players[i]<<" n: "<<n<<endl;
        // cout<<"---- players[i]: "<<players[i]<<" (n+1)*k): "<<(n+1)*k<<endl;
        
        if((ll)players[i]>=(n+1)*m){
            int need=players[i]/m;
            int plus=need-n;
            answer+=plus;
            q.push({i+k,plus});
            n=need;
            
            // cout<<"-- need: "<<need<<" plus: "<<plus<<endl;
        }
        
    }
    
    return answer;
}