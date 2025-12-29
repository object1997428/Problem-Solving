#include <string>
#include <vector>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <cassert>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int arr[100001];

int solution(int n, int m, vector<int> section) {
    
    memset(arr,1,sizeof(arr));
    for(auto k:section){
        arr[k-1]=0;
    }
    
    int cnt=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            cnt++;
            for(int j=0;j<m;j++){
                if(i+j>=n) break;
                arr[i+j]=1;
            }
            i+=m-1;
        }
    }
    
    
    
    int answer = cnt;
    return answer;
}