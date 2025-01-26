#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <climits>
#include <cassert>
#include <cmath>
using namespace std;
typedef long long ll;


int N;
ll limit;
vector<int> diffs,times;

bool valid(int x){
    
    ll sum=0;
    for(int i=0;i<N;i++){
        int diff=diffs[i], time_cur=times[i];
        int time_pre=(i-1)>=0?times[i-1]:0;
        // cout<<"i: "<<i<<" time_pre: "<<time_pre<<endl;
        if(diff<=x) sum+=time_cur;
        else{
            sum+=(diff-x)*(time_pre+time_cur)+time_cur;
        }
    }
    // cout<<"x: "<<x<<" sum: "<<sum<<endl;
    return (sum<=limit);
}

int solve(int maxd){
    int l=1,r=maxd;
    int ans=r;
    while(l<=r){
        int m=(l+r)/2;
        if(valid(m)){
            ans=min(ans,m);
            r=m-1;
        }
        else l=m+1;
    }
    return ans;
}

int solution(vector<int> _diffs, vector<int> _times, long long _limit) {
    //init
    limit=_limit; diffs=_diffs, times=_times;
    N=diffs.size();
    
    //solve
    int maxd=0;
    for(int i=0;i<diffs.size();i++){
        maxd=max(maxd,diffs[i]);
    }
    
    // cout<<"maxd: "<<maxd<<endl;
    
    int answer = solve(maxd);
    return answer;
}