#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <climits>
#include <cmath>
#include <cassert>
#include <iostream>
using namespace std;
typedef pair<int,int> pii;

int win[46];

int getRate(int winCnt){
    if(winCnt==6) return 1;
    else if(winCnt==5) return 2;
    else if(winCnt==4) return 3;
    else if(winCnt==3) return 4;
    else if(winCnt==2) return 5;
    return 6;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    //init
    for(int x:win_nums) win[x]=1;
    
    //
    int oCnt=0;
    int winCnt=0;
    for(int x:lottos){
        if(x!=0){
            if(win[x]==1) winCnt++;
        }
        else oCnt++;
    }
    
    vector<int> answer;
    answer.push_back(getRate(winCnt+oCnt));
    answer.push_back(getRate(winCnt));
    return answer;
}