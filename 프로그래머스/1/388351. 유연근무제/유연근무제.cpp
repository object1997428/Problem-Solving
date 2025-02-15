#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <climits>
#include <cassert>
#include <iostream>
#include <cmath>
using namespace std;
typedef pair<int,int> pii;
typedef long long int ll;
#define endl '\n'

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    startday--;
    int N=schedules.size();
    for(int i=0;i<N;i++){
        int pre=schedules[i];
        int sh=pre/100;
        int sm=pre%100;
        sm+=10;
        if(sm>=60) sh++, sm-=60;
        assert(sm>=0);
        schedules[i]=sh*100+sm;
    }
    
    int answer = 0;
    for(int i=0;i<N;i++){
        int chk=1;
        for(int j=0;j<7;j++){
            if((startday+j)%7>=5) continue;;
            if(timelogs[i][j]>schedules[i]){
                chk=0; 
                break;
            }
        }
        if(chk==1) answer++;
    }
    
    
    return answer;
}