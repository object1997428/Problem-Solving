#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <climits>
#include <cassert>
#include <cmath>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int cal(int k){
    int ret=0;
    while(k>1){
        if(k%2==1) k--;
        k/=2;
        ret++;
    }
    return ret;
}

int solution(vector<int> num_list) {
    
    int answer = 0;
    for(int i=0;i<num_list.size();i++){
        int ret=cal(num_list[i]);
        answer+=ret;
    }
    
    
    
    return answer;
}