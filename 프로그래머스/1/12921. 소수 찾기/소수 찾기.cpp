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
#define MAX 1000000

int chk[1000001]; //0: 맞음. 1: 아님

int solve(int n){
    int ret=0;
    for(int i=2;i<=n;i++){
        if(chk[i]) continue;
        //맞음
        ret++;
        for(int j=i+i;j<=n;j+=i) chk[j]=1;
        
    }
    return ret;
}


int solution(int n) {
    int answer = solve(n);
    return answer;
}