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

int getStringSize(string str,int p){
    //i만큼 자르기
    vector<string> v;
    int sz=str.size();
    for(int i=0;i<sz;i+=p){
        string s;
        for(int j=0;j<p&&i+j<sz;j++){
            s.push_back(str[i+j]);
        }
        v.push_back(s);
    }
    
    // for(string x: v) cout<<x<<" "; cout<<endl;
    
    //같으면 압축
    int cnt=0;
    string ret="";
    for(int i=1;i<v.size();i++){
        // cout<<"i: "<<i<<endl;
        if(v[i]==v[i-1]){
            cnt++;
        }
        else {
            if(cnt>0){
                ret+=to_string(cnt+1);
                
                ret+=v[i-1];
                cnt=0;
            }
            else ret+=v[i-1];
        } 
    }
    
    if(cnt>0){
        ret+=to_string(cnt+1);
        ret+=v.back();
        cnt=0;
    }
    else ret+=v.back();
    // cout<<"p: "<<p<<" ret: "<<ret<<endl;
    return ret.size();
}

int solution(string s) {
    int ans=s.size();
    int sz=s.size();
    for(int i=1;i<s.size();i++){
        // if(sz%i>0) continue;
        int ret=getStringSize(s,i);
        ans=min(ans,ret);
    }
    
    return ans;
}