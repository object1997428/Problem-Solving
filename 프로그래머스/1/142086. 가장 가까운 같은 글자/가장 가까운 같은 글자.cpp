#include <string>
#include <vector>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cassert>
#include <cmath>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
int maxWord[27];

vector<int> solution(string s) {
    memset(maxWord,-1,sizeof(maxWord));
    int N=s.size();
    
    vector<int> answer;
    for(int i=0;i<N;i++){
        char c=s[i];
        if(maxWord[c-'a']==-1) answer.push_back(-1);
        else{
            // cout<<"i-maxWord[c-'a']: "<<i-maxWord[c-'a']<<endl;
            answer.push_back(i-maxWord[c-'a']);            
        }
        maxWord[c-'a']=i;
    }
    
    
    
    return answer;
}