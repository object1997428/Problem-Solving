#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
#include <climits>
#include <cmath>
#include <cassert>
#include <iostream>
#include <unordered_map>
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> pip;
typedef long long ll;
#define endl '\n'

vector<int> g[1000001];
unordered_map<ll,int> m1; //간선 방문 체크
int N;
int in[1000001],out[1000001];
vector<int> srcCandidate;

int chk[1000001]; //방문체크
int vCnt,eCnt,is2;

ll hashyx(ll y,ll x){
    return (y*1000001)+x;
}

void dfs(int p,int c,int src){
    
    if(++chk[c]==1) vCnt++;
    else if((c==src&&chk[c]>=3)||(c!=src&&chk[c]>=2)) is2=1;
    
    for(int i=0;i<g[c].size();i++){
        int next=g[c][i];
        // if(next!=p){
            if(m1[hashyx(c,next)]==0){
                m1[hashyx(c,next)]=1; eCnt++;
                dfs(c,next,src);
            }
        // }
    }
}

int findType(int src){
    vCnt=0,eCnt=0,is2=0;
    dfs(-1,src,src);
    
    // cout<<"v: "<<src<<" vCnt: "<<vCnt<<" eCnt: "<<eCnt<<endl;
    if(is2==1) return 2;
    if(vCnt==eCnt) return 0;
    else if(vCnt==eCnt+1) return 1;
}

vector<int> solution(vector<vector<int>> edges) {
    //init
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        g[u].push_back(v);
        N=max(N,u);
        N=max(N,v);
        out[u]++,in[v]++;
    }

    //solve
    int src=0, srcOut=0;
    for(int i=1;i<=N;i++){
        if(in[i]==0&&out[i]>0){
            if(srcOut<out[i]) src=i, srcOut=out[i];
        }
    }
    cout<<"src: "<<src<<endl;
    // if(srcCandidate.size()>1){
    //     cout<<"시작점 2개 이상"<<endl;
    //     for(auto x:srcCandidate) cout<<x<<" ";
    //     cout<<endl;
    // }
    
    //src에서 뻗어져 나오는 정점 하나씩 찾기
    int typeCnt[3]={0,0,0};
    for(int i=0;i<g[src].size();i++){
        int v=g[src][i];
        int type=findType(v);
        
        // cout<<"v: "<<v<<" type: "<<type<<endl;
        typeCnt[type]++;
    }
    
    vector<int> answer;
    answer.push_back(src);
    answer.push_back(typeCnt[0]);
    answer.push_back(typeCnt[1]);
    answer.push_back(typeCnt[2]);
    return answer;
}