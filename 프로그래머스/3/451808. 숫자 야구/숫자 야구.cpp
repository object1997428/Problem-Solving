#include <string>
#include <vector>
#include <string.h>
#include <iostream>
#include <climits>
#include <cassert>
#include <cmath>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
typedef pair<string,pii> pip;
typedef long long ll;

extern string submit(int);


vector<int> v;//포함되는 숫자들

int callCnt;

vector<pip> l;
vector<string> cand;

int curN[10]; //이번턴에서 후보들의 각 자리수 체크
vector<int> curv;

string ans;
bool flag;


pii CallSubmit(string password){
    callCnt++;
    
    int p=stoi(password);
    string ret=submit(p);
    cout<<"password: "<<password<<" ret: "<<ret<<endl;
    
    int s=ret[0]-'0';
    int b=ret[3]-'0';
    l.push_back({password,{b,s}});
    // cout<<"l.back(): "<<l.back().first<<endl;
    
    if(s==4){
        ans=password;
        flag=true;
    }
    
    return {b+s,s};
}

bool isValid(string k){
    //같은수를 중복으로 넣지 않게
    if(k[0]==k[1]||k[0]==k[2]||k[0]==k[3]) return false;
    if(k[1]==k[2]||k[1]==k[3]) return false;
    if(k[2]==k[3]) return false;
    if(k[0]=='0'||k[1]=='0'||k[2]=='0'||k[3]=='0') return false;

    for(int i=0;i<l.size();i++){
        string num=l[i].first;
        int b=l[i].second.first;
        int s=l[i].second.second;
        if(num==k){
            // cout<<"num: "<<num<<" k: "<<k<<endl;
            return false;
        }
        
        //k랑 num이랑 비교해서 b랑 s일치하는지 확인하기
        int nb=0,ns=0;
        if(k[0]==num[0]) ns++;
        if(k[0]==num[1]) nb++;
        if(k[0]==num[2]) nb++;
        if(k[0]==num[3]) nb++;
        
        if(k[1]==num[0]) nb++;
        if(k[1]==num[1]) ns++;
        if(k[1]==num[2]) nb++;
        if(k[1]==num[3]) nb++;
        
        if(k[2]==num[0]) nb++;
        if(k[2]==num[1]) nb++;
        if(k[2]==num[2]) ns++;
        if(k[2]==num[3]) nb++;
        
        if(k[3]==num[0]) nb++;
        if(k[3]==num[1]) nb++;
        if(k[3]==num[2]) nb++;
        if(k[3]==num[3]) ns++;
        
        
        if(nb!=b||ns!=s) return false;
    }
    return true;
}

void findCandiate(){
    while(!cand.empty()) cand.pop_back();
    
    //password 후보 찾기
    for(int i=1000;i<=9999;i++){
        string str=to_string(i);
        
        if(isValid(str)){
            cand.push_back(str);
        }
    }
}



void solve(){
    //포함된 숫자 알아내기
    auto ret=CallSubmit("1234"); 
    // ret=CallSubmit("5678");
  
    //숫자 4개 찾기
    int tmpcnt=0;
    while(!flag){
        
        findCandiate();
        
        // cout<<"flag: "<<flag<<" ans: "<<ans<<" cand.size(): "<<cand.size()<<endl;
        if(cand.size()==1){
            ans=cand[0];
            flag=true;
            break;
        }
        else if(!cand.empty()) CallSubmit(cand[0]);
        else if(cand.empty()) assert(0);
    }
    
    return;
}

int solution(int n) {
    ans=""; flag=false;
    solve();
    
    // cout<<"callCnt: "<<callCnt<<endl;
    // cout<<"ans: "<<ans<<endl;
    
    int password=1000*(ans[0]-'0')+100*(ans[1]-'0')+10*(ans[2]-'0')+(ans[3]-'0');
    return password;
}