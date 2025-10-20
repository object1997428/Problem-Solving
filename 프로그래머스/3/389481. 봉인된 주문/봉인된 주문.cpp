#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cmath>
#include <cassert>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;

ll N;
vector<string> temp;

int comp(string a, string b){
        if(a.size()==b.size()) return a<b;
        return a.size()<b.size();
}


pii findWord(int len, ll k){
    char c='a';
    for(int i=0;i<26;i++){
        c='a'+i;
        ll minus=pow(26,len-1);
        
        if(k-minus<=0) break; //'c'를 앞에두고, 남은 글자수에서 k번째인것
        else k=k-minus;
    }
    return {c,k};
}

ll findCnt(string str){
    ll cnt=0;
    int len=str.size();
    
    for(int i=1;i<len;i++){
        cnt+=pow(26,i);
    }
    for(int i=0;i<str.size();i++){
        int c=str[i]-'a';
        ll plus=pow(26,len-(i+1))*c;
        cnt+=plus;
    }
    return cnt+1;
}

pii findLen(ll k){
    int cnt=k;
    int l=1;
    for(l=1;l<=13;l++){
        ll minus=pow(26,l);
        if(k-minus<0) break;
        else k=k-minus;
    }
    
    return {l,k}; //l글자수에서 k번째인 알파벳
}

string solution(long long n, vector<string> bans) {
    
    
    N=n;
    sort(bans.begin(),bans.end(),comp);
    // for(auto ban: bans) cout<<ban<<endl;
    // cout<<endl;

    
    //bans에서 n번째 안에 있는 알파벳 개수 카운트
    int plus=0;
    ll K=n;
    for(int i=0;i<bans.size();i++){
        string str=bans[i];
        ll strCnt=findCnt(str);
    
        if(strCnt<=K){
            // cout<<"str: "<<str<<" strCnt: "<<strCnt<<endl;
            K++;
        }
    }
    // cout<<"K: "<<K<<endl;
    
    //K번째 알파벳 찾기
    //글자수 찾기
    pii ret=findLen(K);
    ll len=ret.first;
    ll k=ret.second;
    // cout<<"len: "<<len<<" k: "<<k<<endl;
    
    //알파벳 찾기
    string kstr="";
    for(int i=len;i>=1;i--){
        pii ret2=findWord(i,k);
        k=ret2.second;
        char c=ret2.first;
        
        // cout<<"c: "<<c<<" k: "<<k<<endl;
        kstr+=c;
    }
    // cout<<"kstr: "<<kstr<<endl;
    
    string answer = kstr;
    return answer;
}