#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cassert>
#include <cmath>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int skipList[27];

string solution(string s, string skip, int index) {
    for(int i=0;i<skip.size();i++){
        char c=skip[i];
        skipList[c-'a']=1;
    }
    
    for(int i=0;i<s.size();i++){
        char c=s[i];
        int count=0;
        // cout<<"s[i]: "<<s[i]<<endl;
        while(count<index){
            if(++c>'z') c='a';
            if(skipList[c-'a']!=1) count++;
            // cout<<"c: "<<c<<endl;
        }
        
        s[i]=c;
    }
    
    
    string answer = s;
    return answer;
}