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


int solve(int cur){
    if(cur<10){//한자리수면
        return min(cur, 10-cur+1);
    }
    if(cur==0) return 0;
    
    int k=cur%10;
    
    int next=cur-k;
    next/=10;
    int ret1=solve(next)+k;
    
    next=cur+(10-k);
    next/=10;
    int ret2=solve(next)+(10-k);
    
    
    int ret=min(ret1, ret2);
    return ret;
}


int solution(int start) {
    int ret=solve(start);
    
    return ret;
}