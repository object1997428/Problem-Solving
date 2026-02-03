#include <string>
#include <vector>
#include <string.h>
#include <iostream>
#include <climits>
#include <cmath>
#include <cassert>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int solution(vector<vector<int>> sizes) {
    int N=sizes.size();
    
    int maxL=0,maxR=0; //L>=R
    for(int i=0;i<N;i++){
        if(sizes[i][1]>sizes[i][0]) swap(sizes[i][0], sizes[i][1]);
        
        maxL=max(maxL,sizes[i][0]);
        maxR=max(maxR,sizes[i][1]);
        
    }
    
    // cout<<"maxL: "<<maxL<<" maxR: "<<maxR<<endl;
    
    
    int answer = maxL*maxR;
    return answer;
}