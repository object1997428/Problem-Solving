#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <climits>
#include <cassert>
#include <iostream>
#include <cmath>
using namespace std;
typedef pair<int,int> pii;
typedef long long int ll;
#define endl '\n'

int N;
vector<vector<int>> q;
vector<int> ans;
int chked[31];
int answer = 0;

bool isValid(){
    for(int i=0;i<q.size();i++){
        int cnt=0;
        for(int j=0;j<q[i].size();j++){
            if(chked[q[i][j]]) cnt++;
        }
        if(cnt!=ans[i]) return false;
    }
    return true;
}

void pick(int start,int cnt){
    if(cnt==5){
        if(isValid()){
            answer++;
        }
        return;
    }
    
    for(int i=start;i<=N;i++){
        if(chked[i]==0){
            chked[i]=1;
            pick(i+1,cnt+1);
            chked[i]=0;
        }
    }
}

int solution(int n, vector<vector<int>> _q, vector<int> _ans) {
    //init
    N=n; q=_q; ans=_ans;
    
    //solve
    pick(1,0);
    
    return answer;
}