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
vector<pii> v1;
vector<int> cand;

int solution(vector<vector<int>> scores) {
    N=scores.size();
    int a=scores[0][0], b=scores[0][1];
    
    for(int i=0;i<N;i++){
        v1.push_back({scores[i][0],-scores[i][1]});
    }
    sort(v1.begin(),v1.end(),greater<>());
    
    for(int i=0;i<N;i++){
        int s1=scores[i][0], s2=scores[i][1];
        
        bool isCandidate=true;
        for(int j=0;j<N;j++){
            if(v1[j].first<s1) break;
            //[0]도 크고, [1]도 크면
            // cout<<"-v1[j].second: "<<-v1[j].second<<" s2: "<<s2<<endl;
            else if(v1[j].first==s1) continue;
            if(-v1[j].second>s2){
                isCandidate=false;
            }
        }
        
        if(isCandidate){
            // cout<<"s1: "<<s1<<" s2: "<<s2<<endl;
            cand.push_back(s1+s2);
        }
        else if(s1==a&&s2==b) return -1;
    }
    
    
    sort(cand.begin(),cand.end());
    int idx=upper_bound(cand.begin(),cand.end(),a+b)-cand.begin();
    int ans=cand.size()-idx+1;
    
    cout<<"cand.size(): "<<cand.size()<<" idx: "<<idx<<endl;
    
    
    return ans;
}