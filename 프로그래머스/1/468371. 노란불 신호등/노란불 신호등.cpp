#include <string>
#include <vector>
#include <iostream>
#include <string.h>
#include <climits>
#include <cmath>
#include <cassert>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define endl '\n'

int arr[3200001];

int solution(vector<vector<int>> signals) {
    
    int N=signals.size();
    int len=1;
    for(int i=0;i<N;i++){
        int g=signals[i][0], y=signals[i][1], r=signals[i][2];
        len*=(g+y+r);
    }
    cout<<"len: "<<len<<endl;
    for(int i=0;i<N;i++){
        int g=signals[i][0], y=signals[i][1], r=signals[i][2];
        int start=g+1;
        while(start<=len){
            for(int j=0;j<y;j++){
                if(start+j>len) break;
                arr[start+j]++;
                // cout<<start+j<<" ";
            }
            if(start>len) break;
            start+=y+r+g;
        }
        // cout<<endl;cout<<endl;
    }
    
    for(int i=1;i<=len;i++){
        if(arr[i]==N) return i;
    }
    return -1;
}