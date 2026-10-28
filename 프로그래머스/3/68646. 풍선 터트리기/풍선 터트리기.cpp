#include <string>
#include <vector>
#include <iostream>
#include <string.h>
using namespace std;

int minL[1000001];
int minR[1000001];
int N;

int solution(vector<int> a) {
    N=a.size();
    minL[0]=a[0], minR[N-1]=a[N-1];
    for(int i=1;i<N;i++){
        minL[i]=min(minL[i-1],a[i]);
    }
    for(int i=N-2;i>=0;i--){
        minR[i]=min(minR[i+1],a[i]);
    }
    
    int cnt=2;
    for(int i=1;i<N-1;i++){
        if(minL[i-1]<a[i]&&minR[i+1]<a[i]) continue;
        else cnt++;
    }
    
    
    
    int answer = cnt;
    return answer;
}