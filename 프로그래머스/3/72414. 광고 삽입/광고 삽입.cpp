#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <cassert>
#include <climits>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;

vector<pii> v; //{time,0/1}; 0: 닫힘, 1:열림
int sum[400001];

int time2int(string str){
    int h=stoi(str.substr(0,2));
    int m=stoi(str.substr(3,2));
    int s=stoi(str.substr(6,2));
    // cout<<"h: "<<h<<" m: "<<m<<" s: "<<s<<endl;
    return h*60*60+m*60+s;
}

string int2time(int t){
    int h=t/3600;
    int m=(t%3600)/60;
    int s=t%60;
    
    string sh=""; 
    if(h<10) sh += '0';
    sh += to_string(h);
        
    string sm=""; if(m<10) sm+="0";
    sm+=to_string(m);
    string ss=""; if(s<10) ss+="0";
    ss+=to_string(s);
    
    return sh+":"+sm+":"+ss;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    //init
    int total=time2int(play_time);
    int adTime=time2int(adv_time);
    
    //solve
    //누적합 구하기
    for(int i=0;i<logs.size();i++){
        string log=logs[i];
        int start=time2int(log.substr(0,8));
        int end=time2int(log.substr(9));
        
        sum[start]++, sum[end]--;
    }
    
    for(int i=1;i<total;i++){
        sum[i]+=sum[i-1];
    }
    
    //제일 큰 구간 구하기
    int cur=0;
    ll now=0;
    for(int i=0;i<adTime;i++) now+=sum[i];
    
    int t=0; 
    ll maxNow=now;
    for(int cur=1;cur<=total;cur++){
        now-=sum[cur-1];
        int e=cur+adTime;
        if(e>total) break;
        now+=sum[e-1];
        
        if(maxNow<now){
            t=cur;
            maxNow=now;
            
            
        }
    }
    
    int h=t/3600;
    int m=(t%3600)/60;
    int s=t%60;


    string sh=""; 
    if(h<10) sh += '0';
    sh += to_string(h);
        
    string sm=""; if(m<10) sm+="0";
    sm+=to_string(m);
    string ss=""; if(s<10) ss+="0";
    ss+=to_string(s);
    
    string answer = "";
    answer+=sh+":"+sm+":"+ss;
    
    return answer;
}