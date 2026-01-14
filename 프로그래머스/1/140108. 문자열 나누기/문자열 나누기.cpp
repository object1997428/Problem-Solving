#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <climits>
#include <cmath>
#include <cassert>
#include <iostream>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int solution(string s) {
    int N=s.size();
    
    int start=0, end=0;
    int answer = 0;
    int count=0;
    while(start<N){
        char first=s[start];
        int cnt1=1, cnt2=0;
        for(end=start+1;end<N;end++){
            if(s[end]==s[start]) cnt1++;
            else cnt2++;
            
            if(cnt1==cnt2) break;
        }
        answer++;

        start=end+1;
        // cout<<"start: "<<start<<" end: "<<end<<endl;
        // if(start>=N) break;
    }
    
    
    return answer;
}