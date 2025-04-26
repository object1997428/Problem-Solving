#include <string>
#include <vector>
#include <string.h>
#include <iostream>
#include <climits>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
typedef pair<int,string> ps;
#define endl '\n'


// vector<string> v;
string v;
int chked[27];
int maxCnt;
int chkCnt[11];//pick해야하는 cnt

map<string,int> m1;
string cur;
vector<ps> v1;

void solve(int cnt,int start){
    
    // if(cnt==0) cout<<"v: "<<v<<endl;
    //부분집합 완성
    if(chkCnt[cnt]){
        m1[cur]=m1[cur]+1;
    }
    if(cnt>=maxCnt) return;
    
    for(int i=start;i<v.size();i++){
        char next=v[i];
        if(chked[next-'A']==0){
            chked[next-'A']=1;
            cur.push_back(next);
            solve(cnt+1,i+1);
            cur.pop_back();
            chked[next-'A']=0;
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    
    for(int x:course){
        chkCnt[x]=1;
        maxCnt=max(maxCnt,x);
    }
    int N=orders.size();
    for(int i=0;i<N;i++){
        sort(orders[i].begin(),orders[i].end());
        v=orders[i];
        solve(0,0);
    }
    
    //result
    int limit[11]={};
    for(auto it=m1.begin();it!=m1.end();it++){
        // cout<<it->first<<" "<<it->second<<endl;
        // v1.push_back({it->second,it->first});
        int sz=(it->first).size();
        limit[sz]=max(limit[sz],it->second);
        // if(it->first=="AC") cout<<"limit[sz]: "<<limit[sz]<<" it->second: "<<it->second<<endl;
    }
    vector<string> answer;
    for(auto it=m1.begin();it!=m1.end();it++){
        int sz=(it->first).size();
        if(limit[sz]>=2&&limit[sz]==it->second){
            // cout<<"limit[sz]: "<<limit[sz]<<endl;
            answer.push_back(it->first);
        }
    }
    
    
    sort(answer.begin(),answer.end());
    
    return answer;
}