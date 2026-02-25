#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <climits>
#include <cmath>
#include <cassert>
#include <iostream>
#include <unordered_map> m1;
#define endl '\n'
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

vector<string> v1,v2,tmp;
vector<string> cals;
unordered_map<string, int> chked;


void split(string s){
    string cur="";
    for(int i=0;i<s.size();i++){
        if(s[i]=='*'||s[i]=='+'||s[i]=='-') {
            v1.push_back(cur);
            
            string c=""; c+=s[i];
            v1.push_back(c);
            if(chked[c]==0){
                cals.push_back(c);
                chked[c]=1;
            }
            
            cur="";
        }
        else cur+=s[i];
    }
    v1.push_back(cur);

    // for(auto x:v1){
    //     cout<<x<<" ";
    // }cout<<endl;
}

ll calculate(ll v1, ll v2, string c){
    if(c=="+") return v1+v2;
    if(c=="-") return v1-v2;
    return v1*v2;
}

ll solve(){
    v2=v1;
    
    for(int k=0;k<cals.size();k++){
        string c=cals[k];
        //c기호만 앞에서부터 계산해주기
        for(int i=0;i<v2.size();i++){
            if(v2[i]==c){
                assert(i-1>=0);
                string prevS=tmp.back();
                if(prevS=="+"||prevS=="-"||prevS=="*") cout<<"i-1가 숫자 아님"<<endl;
                ll prev=stoll(prevS);
                assert(i+1<v2.size());
                if(v2[i+1]=="+"||v2[i+1]=="-"||v2[i+1]=="*") cout<<"i+1가 숫자 아님"<<endl;
                ll next=stoll(v2[i+1]);
                
                ll res=calculate(prev,next,c);
                tmp.pop_back();
                tmp.push_back(to_string(res));
                
                // for(auto x:tmp) cout<<x<<" ";
                // cout<<endl;
                
                i++;
            }
            else {
                tmp.push_back(v2[i]);
                // for(auto x:tmp) cout<<x<<" ";
                // cout<<endl;
            }
        }
        v2=tmp;
        while(!tmp.empty()) tmp.pop_back();
    }
    return stoll(v2.back());
}

long long solution(string expression) {
    
    split(expression);
    sort(cals.begin(),cals.end());
    
    ll ans=0;
    do{
        // for(auto x:cals) cout<<x<<" ";
        // cout<<endl;
        
        //우선순위 고정
        //우선순위에 따라서 계산하기
        ll ret=abs(solve());
        // cout<<"ret: "<<ret<<endl;
        ans=max(ret,ans);
        
    }while(next_permutation(cals.begin(),cals.end()));
    
    
    
    long long answer = ans;
    return answer;
}