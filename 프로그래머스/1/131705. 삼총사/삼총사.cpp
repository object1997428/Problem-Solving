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
typedef long long ll;

int ans;
int N;
vector<int> arr;
void solve(int cnt,int start,int sum){
    if(cnt==3){
        if(sum==0) ans++;
        return;
    }
    
    for(int i=start;i<N;i++){
        solve(cnt+1,i+1,sum+arr[i]);
    }
}

int solution(vector<int> number) {
    N=number.size(),ans=0;
    arr=number;
    
    solve(0,0,0);
    
    
    int answer = ans;
    return answer;
}