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

int cnt1[11],cnt2[11];
vector<int> v1;

string solution(string X, string Y) {
    
    for(int i=0;i<X.size();i++){
        int x=X[i]-'0';
        cnt1[x]++;
    }
    
    for(int i=0;i<Y.size();i++){
        int x=Y[i]-'0';
        cnt2[x]++;
    }
    
    for(int i=0;i<=9;i++){
        int count=min(cnt1[i],cnt2[i]);
        if(count>0){
            for(int j=0;j<count;j++){
                v1.push_back(i);
            }
        }
    }
    
    if(v1.empty()) return "-1";
    
    sort(v1.begin(),v1.end(),greater<>());
    if(v1[0]==0) return "0";
    
    
    string answer = "";
    for(int i=0;i<v1.size();i++){
        answer+=v1[i]+'0';
    }
    
    
    
    return answer;
}