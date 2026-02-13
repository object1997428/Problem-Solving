#include <vector>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cassert>
#include <cmath>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

vector<int> v1,arr;
int N, ans;

bool isValid(int k){
    for(int i=2;i*i<=k;i++){
        if(k%i==0) return false;
    }
    return true;
}

void getSum(int start,int sum){
    if(v1.size()==3){
        if(isValid(sum)) ans++;
        return;
    }
    
    for(int i=start;i<N;i++){
        if(!v1.empty()&&v1.back()==arr[i]) continue;
        v1.push_back(arr[i]);
        getSum(i+1,sum+arr[i]);
        v1.pop_back();
    }
}

int solution(vector<int> nums) {
    arr=nums;
    sort(arr.begin(),arr.end());
    N=nums.size();
    
    getSum(0,0);
    
    int answer = ans;
    return answer;
}