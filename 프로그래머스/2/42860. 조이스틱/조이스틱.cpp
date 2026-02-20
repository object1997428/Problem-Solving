#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cassert>
#include <cmath>
using namespace std;

int N;
vector<int> v1;
int chked[21];
int ans;

void findOrder(int cnt, int last, int sum){
    if(sum>=ans) return;
    if(cnt==v1.size()){
        ans=min(ans,sum);
        return;
    }
    
    for(int i=0;i<v1.size();i++){//i: v1의 인덱스
        int next=v1[i]; //next: v1[i]의 값=name의 위치 중 하나
        assert(next<N);
        if(chked[next]==0){
            chked[next]=1;
            
            int l=next, r=last;
            if(l>r) swap(l,r);
            
            int leftCnt=l+1+(N-1)-r;
            int rightCnt=r-l;
            int plus=min(leftCnt,rightCnt);
            
            findOrder(cnt+1,next,sum+plus);
            
            chked[next]=0;

        }
    }
}

int solution(string name) {
    N=name.size();
    ans=INT_MAX;
    
    // cout<<"N: "<<N<<endl;
    for(int i=0;i<N;i++){
        if(name[i]!='A'){
            v1.push_back(i);
            // cout<<"i: "<<i<<endl;
        }
    }
    
    
    findOrder(0,0,0);
    int cnt=ans;
    
    
    for(int i=0;i<N;i++){
        char x=name[i];
        int upCnt=x-'A';
        int downCnt=1+'Z'-x;
        // cout<<"x: "<<x<<" "<<min(upCnt,downCnt)<<endl;
        cnt+=min(upCnt,downCnt);
    }
    
    int answer = cnt;
    return answer;
}