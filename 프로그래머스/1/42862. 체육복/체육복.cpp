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

int arr[31];

int solution(int n, vector<int> lost, vector<int> reserve) {
    
    //init
    for(int i=0;i<n;i++){
        arr[i]=1;
    }
    
    for(int i=0;i<reserve.size();i++){
        int k=reserve[i]-1;
        arr[k]++;
    }
    
    for(int i=0;i<lost.size();i++){
        int k=lost[i]-1;
        arr[k]--;
    }
    
    //solve
    for(int i=n-1;i>=0;i--){
        if(arr[i]==0){
            if(i+1<n&&arr[i+1]>1) arr[i+1]--, arr[i]++;
            else if(i-1>=0&&arr[i-1]>1) arr[i-1]--, arr[i]++;
        }
    }
    
    int cnt=0;
    for(int i=0;i<n;i++){
        if(arr[i]>0) cnt++;
    }
    
    
    
    int answer = cnt;
    return answer;
}