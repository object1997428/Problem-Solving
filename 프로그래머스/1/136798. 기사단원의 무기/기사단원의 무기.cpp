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

vector<int> v;

int cal(int k){
    int cnt=0;
    for(int i=1;i*i<=k;i++){
        if(k%i==0){
            v.push_back(i);
            v.push_back(k/i);
        }
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    cnt=v.size();
    v.clear();
    return cnt;
}

int solution(int number, int limit, int power) {
    
    int answer = 0;
    for(int i=1;i<=number;i++){
        int cnt=cal(i);
        if(cnt>limit) cnt=power;
        // cout<<"cnt: "<<cnt<<endl;
        
        answer+=cnt;
    }
    
    
    return answer;
}