#include <string>
#include <vector>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <climits>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

priority_queue<int,vector<int>,greater<>> q;


vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    
    for(int x:score){
        if(q.size()<k) q.push(x);
        else if(q.size()>=k&&q.top()<x){
            q.pop();
            q.push(x);
        }
        
        if(!q.empty()) answer.push_back(q.top());
    }
    
    
    
    return answer;
}