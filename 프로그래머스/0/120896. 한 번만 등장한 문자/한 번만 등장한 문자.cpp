#include <string>
#include <vector>
#include <iostream>
using namespace std;
int cnt[30];

string solution(string s) {
    for(int i=0;i<s.size();i++){
        char c=s[i];
        cnt[c-'a']++;
        
        // cout<<"c: "<<c<<" c-'0': "<<c-'0'<<" cnt[c-'0']: "<<cnt[c-'a']<<endl;
    }
    
    string answer = "";
    for(int i=0;i<27;i++){
        if(cnt[i]==1){
            char c='a'+i;
            // cout<<"c: "<<c<<endl;
            
            answer.push_back(c);
        }
    }
    
    
    
    return answer;
}