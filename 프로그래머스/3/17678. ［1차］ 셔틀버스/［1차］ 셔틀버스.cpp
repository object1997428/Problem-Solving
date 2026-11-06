#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cassert>
#include <cmath>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

queue<int> wait;

string solution(int n, int t, int m, vector<string> timetable) {
    
    sort(timetable.begin(),timetable.end());
    // for(string s: timetable) cout<<"s: "<<s<<endl;
    
    int cur=9*60-t;
    int tidx=0;
    int maxT=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        //셔틀 하나에 대해서
        cur+=t;
        
        //탈수있는 인원 추가
        for(;tidx<timetable.size();tidx++){
            int h=stoi(timetable[tidx].substr(0,2));
            int m=stoi(timetable[tidx].substr(3,2));
            // cout<<"h: "<<h<<" m: "<<m<<endl;
            int x=h*60+m;
            if(x<=cur){
                // cout<<"i: "<<i<<" x: "<<x<<endl;
                wait.push(x);
            }
            else break;
        }
        
        //태우기
        cnt=0;
        for(int j=0;j<m;j++){
            if(wait.empty()) break;
            int x=wait.front(); wait.pop();
            maxT=max(maxT,x);
            cnt++;
            
            // cout<<"i: "<<i<<" xx: "<<x<<endl;
        }
    }

    
    //maxT를 string으로 변환
    if(cnt>=m){
        // cout<<"못탔음"<<endl;
        maxT=maxT-1;
    }
    else {
        // cout<<"탈수있음"<<endl;
        maxT=cur;
    }
    
    int h=maxT/60, M=(maxT)%60;
    
    cout<<"h: "<<h<<" M: "<<M<<endl;
    string sh=to_string(h);
    if(h<10) sh='0'+sh;
    string sm=to_string(M);
    if(M<10) sm='0'+sm;
    
    
    string answer = sh+":"+sm;
    return answer;

}