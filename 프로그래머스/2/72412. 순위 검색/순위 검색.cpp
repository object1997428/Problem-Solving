#include <string>
#include <vector>
#include <string.h>
#include <iostream>
#include <climits>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
typedef pair<int,string> ps;
#define endl '\n'

vector<int> v[4][3][3][3];
int N,M;
unordered_map<string,int> type;

vector<string> split(string str){
    vector<string> ret;
    char* p=strtok((char*)str.c_str()," ");
    while(p){
        // cout<<p<<" ";
        ret.push_back(p);
        p=strtok(NULL," ");
    }
    
    return ret;
}

vector<int> solution(vector<string> info, vector<string> query) {
    //init
    N=info.size(); M=query.size();
    type["cpp"]=1,type["java"]=2,type["python"]=3;
    type["backend"]=1,type["frontend"]=2;
    type["junior"]=1,type["senior"]=2;
    type["chicken"]=1,type["pizza"]=2;
    type["-"]=0;
    
    for(int i=0;i<N;i++){
        auto ret=split(info[i]);
        int t1=type[ret[0]], t2=type[ret[1]],t3=type[ret[2]],t4=type[ret[3]];
        int score=stoi(ret[4]);
        // cout<<"t1: "<<t1<<" t2: "<<t2<<" t3: "<<t2<<" t4: "<<t4<<" score: "<<score<<endl;
        v[t1][t2][t3][t4].push_back(score);
        
        v[0][t2][t3][t4].push_back(score);
        v[t1][0][t3][t4].push_back(score);
        v[t1][t2][0][t4].push_back(score);
        v[t1][t2][t3][0].push_back(score);
        
        v[0][0][t3][t4].push_back(score);
        v[0][t2][0][t4].push_back(score);
        v[0][t2][t3][0].push_back(score);
        v[t1][0][0][t4].push_back(score);
        v[t1][0][t3][0].push_back(score);
        v[t1][t2][0][0].push_back(score);
        
        v[0][0][0][t4].push_back(score);
        v[0][0][t3][0].push_back(score);
        v[0][t2][0][0].push_back(score);
        v[t1][0][0][0].push_back(score);
        
        v[0][0][0][0].push_back(score);
    }
    
    for(int i=0;i<4;i++)for(int j=0;j<3;j++)for(int a=0;a<3;a++)for(int b=0;b<3;b++){
        sort(v[i][j][a][b].begin(), v[i][j][a][b].end());
    }
    
    
    //solve
     vector<int> answer;
    // cout<<endl<<endl;
    for(int i=0;i<M;i++){
        auto ret=split(query[i]);
        int q1=type[ret[0]], q2=type[ret[2]],q3=type[ret[4]],q4=type[ret[6]];
        int score=stoi(ret[7]);
        
        // cout<<"q1: "<<q1<<" q2: "<<q2<<" q3: "<<q3<<" q4: "<<q4<<" score: "<<score<<endl;
        
        int idx=lower_bound(v[q1][q2][q3][q4].begin(), v[q1][q2][q3][q4].end(),score)-v[q1][q2][q3][q4].begin();
        int count=v[q1][q2][q3][q4].size()-idx;
        // cout<<"idx: "<<idx<<" count: "<<count<<" v[q1][q2][q3][q4].size(): "<<v[q1][q2][q3][q4].size()<<endl;
        
        answer.push_back(count);
    }
    
    
   
    return answer;
}