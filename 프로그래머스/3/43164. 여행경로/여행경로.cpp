#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cmath>
#include <cassert>
#include <unordered_map>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

unordered_map<string,int> m1;
unordered_map<string,int> visited;
vector<int> g[10001];
string Idx2C[10001];
int V,E, Eidx;
vector<int> ans;
vector<int> v1;
int flag=0;

string toKey(int cur,int next){
    ll sum=cur*(10002)+next;
    string ret=to_string(sum);
    return ret;
}

void solve(int cur,int cnt){
    if(cnt==V){
        cout<<"cnt: "<<cnt<<endl;
        ans=v1; flag=1;
        return;
    }
    
    for(int i=0;i<g[cur].size();i++){
        int next=g[cur][i];
        string key=toKey(cur,next);
        if(visited[key]>0){
            visited[key]--;
            v1.push_back(next);
            
            solve(next,cnt+1);
            
            visited[key]++;
            v1.pop_back();
            
            if(flag==1) return;
        }
    }
}


vector<string> solution(vector<vector<string>> tickets) {
    V=tickets.size();
    Eidx=1;
    
    sort(tickets.begin(),tickets.end());
    for(int i=0;i<V;i++){
        string u=tickets[i][0];
        string v=tickets[i][1];
        // cout<<"u: "<<u<<" v: "<<v<<endl;
        if(m1[u]==0){
            Idx2C[Eidx]=u;
            m1[u]=Eidx++; E++;
            
        }
        if(m1[v]==0){
            Idx2C[Eidx]=v;
            m1[v]=Eidx++; E++;
        }
        
        int uIdx=m1[u], vIdx=m1[v];

        g[uIdx].push_back(vIdx);
        string key=toKey(uIdx,vIdx);
        visited[key]++;
    }
    
    int r=m1["ICN"];
    solve(r,0);
    
    vector<string> answer;
    if(ans.empty()){
        return answer;
    }
    
    answer.push_back("ICN");
    for(int i=0;i<ans.size();i++){
        int idx=ans[i];
        answer.push_back(Idx2C[idx]);
    }

    return answer;
}