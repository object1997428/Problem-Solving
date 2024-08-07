#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <climits>
#include <cassert>
#include <cmath>
using namespace std;
typedef pair<int,int> pii;

vector<string> split1(string str){
    vector<string> ret;
    char* p=strtok((char*)str.c_str(),",");
    while(p){
        ret.push_back(p);
        p=strtok(NULL,",");
    }
    return ret;
}

string change(string str){
    string ret="";
    for(int i=0;i<str.size();i++){
        if(str[i]=='#') continue;
        if(i+1<str.size()&&str[i+1]=='#'){
            if(str[i]=='C') ret.push_back('H');
            else if(str[i]=='D') ret.push_back('I');
            else if(str[i]=='F') ret.push_back('J');
            else if(str[i]=='G') ret.push_back('K');
            else if(str[i]=='A') ret.push_back('L');
        }
        else ret.push_back(str[i]);
    }
    return ret;
}


string solution(string m, vector<string> musicinfos) {
    
    string rs="";
    int maxPlayTime=0;
    m=change(m);
    for(string info: musicinfos){
        vector<string> ret=split1(info);
        // for(int i=0;i<ret.size();i++) cout<<"ret[i]: "<<ret[i]<<" "; cout<<endl;
        int sh=stoi(ret[0].substr(0,2));
        int sm=stoi(ret[0].substr(3,4));
        int eh=stoi(ret[1].substr(0,2));
        int em=stoi(ret[1].substr(3,4));
        int playTime=eh*60+em-(sh*60+sm);
        string q=change(ret[3]);
        int len=q.size();
        
        // cout<<"q: "<<q<<endl;
        // cout<<"playTime: "<<playTime<<endl;
        string q2=q;
        if(len>playTime){
           q2=q.substr(0,playTime);
        }
        else if(len<playTime){
            for(int i=0;i<(playTime/len)-1;i++){
                q2+=(q);
            }
            
            string add=q.substr(0,playTime%len);
            q2+=add;
        }
        // cout<<"q2: "<<q2<<endl;
        
//         //이제 찾기
        if(q2.find(m)!=-1){
            // cout<<"find- q2: "<<q2<<endl;
            if(maxPlayTime<playTime){
                rs=ret[2];
                maxPlayTime=playTime;
            }
        }
    }
    
    if(rs=="") rs="(None)";
    string answer = rs;
    return answer;
}