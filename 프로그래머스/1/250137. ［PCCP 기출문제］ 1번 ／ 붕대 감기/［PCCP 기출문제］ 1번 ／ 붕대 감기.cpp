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
#define endl '\n'

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int maxHealth=health;
    int t=bandage[0], x=bandage[1], y=bandage[2];
    int et=0;
    for(int i=0;i<attacks.size();i++) et=max(et,attacks[i][0]);
    
    
    //solve
    int attIdx=0, cnt=0;
    for(int i=1;i<=et;i++){
        if(attacks[attIdx][0]==i){
            cnt=0;
            health-=attacks[attIdx][1];
            if(health<=0) return -1;
            attIdx++;
            continue;
        }
        
        cnt++;
        health=min(health+x,maxHealth);
        if(cnt==t){
            health=min(health+y,maxHealth);
            cnt=0;
        }
    }
    
    
    int answer = health;
    return answer;
}