#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cassert>
#include <queue>
#pragma warning(disable:4996)
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;

int parent[101];
int N;
vector<pii> g[101];
priority_queue<pip,vector<pip>,greater<pip>> q;



int find(int u){
    if(parent[u]==u) return u;
    return parent[u]=find(parent[u]);
}
void merge(int u,int v){
    u=find(u); v=find(v);
    if(u==v) return;
    parent[u]=v;
}

int solution(int n, vector<vector<int>> costs) {
    //init
    N=n;
    for(int i=1;i<=N;i++) parent[i]=i;
    
    
    for(int i=0;i<costs.size();i++){
        int u=costs[i][0], v=costs[i][1], w=costs[i][2];
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        q.push({w,{u,v}});
    }
    
    ll sum=0,cnt=0;
    while(!q.empty()){
        int w=q.top().first;
        int u=q.top().second.first;
        int v=q.top().second.second;
        q.pop();
        
        if(find(u)!=find(v)){
            merge(u,v);
            sum+=w;
            if(++cnt==N-1) break;
        }
        
    }
    
    int answer = sum;
    return answer;
}