#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <climits>
#include <cassert>
#include <cmath>
using namespace std;

int cur;
int total;
int opStart,opEnd;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    //init
    int pm=stoi(pos.substr(0,2));
    int ps=stoi(pos.substr(3,2));
    // cout<<"pm: "<<pm<<" ps: "<<ps<<endl;
    cur=pm*60+ps;
    total=stoi(video_len.substr(0,2))*60+stoi(video_len.substr(3,2));
    opStart=stoi(op_start.substr(0,2))*60+stoi(op_start.substr(3,2));
    opEnd=stoi(op_end.substr(0,2))*60+stoi(op_end.substr(3,2));
    
    //solve
    for(string command:commands){
        if(cur>=opStart&&cur<=opEnd) cur=opEnd;
        
        if(command=="prev"){
            cur=max(0,cur-10);
        }
        else if(command=="next"){
            cur=min(total,cur+10);
        }
        if(cur>=opStart&&cur<=opEnd) cur=opEnd;
    }

    int cm=cur/60, cs=cur%60;
    // cout<<"cm: "<<cm<<" cs: "<<cs<<endl;
    
    string cms=""; 
    cms.push_back('0'+cm/10);
    cms.push_back('0'+cm%10);
    string css=""; 
    css.push_back('0'+cs/10);
    css.push_back('0'+cs%10);
    
    string answer = cms+":"+css;
    return answer;
}