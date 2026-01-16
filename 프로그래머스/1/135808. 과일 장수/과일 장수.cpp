#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <climits>
#include <cassert>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int solution(int k, int m, vector<int> score) {
    sort(score.begin(),score.end(),greater<>());
    int cur=0, count=0, minV=INT_MAX;
    
    int answer = 0;
    while(cur<score.size()){
        minV=min(minV,score[cur]);
        cur++, count++;
        
        if(count==m){
            count=0;
            answer+=minV*m;
            minV=INT_MAX;
        }
    }
    
    
    return answer;
}