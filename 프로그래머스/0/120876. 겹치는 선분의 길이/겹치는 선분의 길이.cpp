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
#define endl '\n'

vector<pii> v;

int solution(vector<vector<int>> lines) {
    for(int i=0;i<lines.size();i++){
        int start=lines[i][0];
        int end=lines[i][1];
        
        v.push_back({start,1});
        v.push_back({end,0});
    }
    sort(v.begin(),v.end());
    
    int cnt=0,sum=0, start=-1;
    for(int i=0;i<v.size();i++){
        int x=v[i].first;
        int type=v[i].second;
        if(type==0){//닫힘
            if(--cnt==1){
                assert(start!=-1);
                sum+=x-start; start=-1;
            }
        }else{//열림
            if(++cnt==2){
                start=x;
            }
        }
    }
    
    int answer = sum;
    return answer;
}