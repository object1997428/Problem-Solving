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
#define endl '\n'


vector<int> g[101][4];
int chked[101];
vector<int> chkedV;
queue<int> q1;
int playCnt,Cnt; //minK, 감염된 최대 노드수
int K,N,S;

void bfs(int t){
    while(!q1.empty()) q1.pop();
    for(int i=0;i<chkedV.size();i++){
        q1.push(chkedV[i]);
    }
    // cout<<"t: "<<t<<endl;
    while(!q1.empty()){
        int u=q1.front(); q1.pop();
        
        for(int i=0;i<g[u][t].size();i++){
            int v=g[u][t][i];
            if(chked[v]==0){
                chked[v]=1;
                chkedV.push_back(v);
                q1.push(v);
            }
        }
    }
}
vector<int> order;

bool isAllchekd(){
    return (chkedV.size()==N);
}

void simulate(){
    // cout<<"------ simulate start"<<endl; <- 왜 이부분에서 세그먼트 오류?
    // 초기화
    memset(chked,0,sizeof(chked));
    chked[S]=1;
    chkedV.clear();
    chkedV.push_back(S);
    
    
    //시뮬
    for(int i=0;i<order.size();i++){
        int t=order[i];
        bfs(t);
        if(isAllchekd()){
            playCnt=min(playCnt,i+1);
            Cnt=N;
            break;
        }
    }
    int curCnt=chkedV.size();
    // cout<<"curCnt: "<<curCnt<<endl;
    Cnt=max(Cnt,curCnt);
}

void pickOrder(int cnt){
    if(Cnt==N) return;
    if(cnt==K){
        simulate();
        return;
    }
    if(cnt>K) return;
    
    
    for(int i=1;i<=3;i++){
        if(!order.empty()&&order.back()==i) continue;
        order.push_back(i);
        pickOrder(cnt+1);
        order.pop_back();
    }
}


int solution(int n, int infection, vector<vector<int>> edges, int k) {
    // 초기화
    K=k; N=n; S=infection;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int t=edges[i][2];
        g[u][t].push_back(v);
        g[v][t].push_back(u);
    }
    
    
    pickOrder(0);
    
    int answer = Cnt;
    return answer;
}