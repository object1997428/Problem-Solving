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

int isValid(string s, int k){
    if(s[k]=='a'){
        if(k+2<s.size()&&s[k]=='a'&&s[k+1]=='y'&&s[k+2]=='a') return 3;
        else return 0;
    }
    if(s[k]=='y'){
        if(k+1<s.size()&&s[k]=='y'&&s[k+1]=='e') return 2;
        else return 0;
    }
    if(s[k]=='w'){
        if(k+2<s.size()&&s[k]=='w'&&s[k+1]=='o'&&s[k+2]=='o') return 3;
        else return 0;
    }
    if(s[k]=='m'){
        if(k+1<s.size()&&s[k]=='m'&&s[k+1]=='a') return 2;
        else return 0;
    }
    return 0;
}

int solution(vector<string> babbling) {
    int N=babbling.size();
    
    int answer = 0;
    for(int i=0;i<N;i++){
        string s=babbling[i];
        int j=0;
        while(j<s.size()){
            int ret=isValid(s,j);
            if(ret==0) break;
            else {
                if(s[j]==s[j+ret]) break;
                else j+=ret;
            }
        }
        if(j==s.size()){
            answer++;
            // cout<<"s: "<<s<<endl;
        }
        assert(j<=s.size());
    }
    
    
    
    return answer;
}