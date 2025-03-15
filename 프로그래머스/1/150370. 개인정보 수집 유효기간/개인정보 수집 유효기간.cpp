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

int month[27];

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    int ty=stoi(today.substr(0,4));
    int tm=stoi(today.substr(5,2));
    int td=stoi(today.substr(8,2));
    int tt=td+tm*28+ty*12*28;
    
    for(int i=0;i<terms.size();i++){
        char x=terms[i][0];  
        int m=stoi(terms[i].substr(2));

        month[x-'A']=m;
    }
    
    vector<int> answer;
    for(int i=0;i<privacies.size();i++){
        int y=stoi(privacies[i].substr(0,4));
        int m=stoi(privacies[i].substr(5,2));
        int d=stoi(privacies[i].substr(8,2));
        
        char x=privacies[i][11];
        
        int sum=d+m*28+y*12*28+month[x-'A']*28;
        if(sum<=tt){
            answer.push_back(i+1);
        }
    }
    
    
    
    return answer;
}