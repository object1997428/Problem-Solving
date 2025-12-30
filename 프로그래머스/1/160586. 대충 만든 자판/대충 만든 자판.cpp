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

int idx[27];

vector<int> solution(vector<string> keymap, vector<string> targets) {
    
    for(int j=0;j<27;j++) idx[j]=INT_MAX;
    
    int N=keymap.size(), M=targets.size();
    for(int i=0;i<N;i++){
        for(int j=0;j<keymap[i].size();j++){
            int k=keymap[i][j]-'A';
            idx[k]=min(idx[k],j);
        }
    }
    
    vector<int> answer;
    for(int i=0;i<M;i++){
        int cnt=0;
        for(int j=0;j<targets[i].size();j++){
            int k=targets[i][j]-'A';
            if(idx[k]==INT_MAX) {
                cnt=-1;
                break;
            }
            
            cnt+=idx[k]+1;
        }
        if(cnt!=-1) answer.push_back(cnt);
        else answer.push_back(-1);
    }
    
    
    
    return answer;
}