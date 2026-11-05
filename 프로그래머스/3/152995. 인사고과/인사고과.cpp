#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cassert>
#include <cmath>
using namespace std;
typedef pair<int,int> pii;

vector<pii> v1;
vector<int> cand;
int N;

int solution(vector<vector<int>> scores) {
    N=scores.size();
    
    for(int i=0;i<N;i++){
        v1.push_back({scores[i][0],-scores[i][1]});
    }
    
    sort(v1.begin(),v1.end(),greater<>());
    
    int secondMax=0;
    for(int i=0;i<N;i++) {
        int s1=v1[i].first;
        int s2=-v1[i].second;
        if(secondMax > s2){
            //후보 아님
            if(s1==scores[0][0]&&s2==scores[0][1]) return -1;
        }
        else {
            secondMax=max(secondMax,s2);
            cand.push_back(s1+s2);
        }
    }
    
    sort(cand.begin(),cand.end());
    int idx=upper_bound(cand.begin(),cand.end(),scores[0][0]+scores[0][1])-cand.begin();
    int ans=cand.size()-idx+1;
    
    
    
    int answer = ans;
    return answer;
}