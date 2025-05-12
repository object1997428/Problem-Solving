#include <string>
#include <vector>
#include <string.h>
#include <iostream>
#include <climits>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define endl '\n'

int N,E,A,B,S;
vector<int> g[201];
ll dist[201][201];
// pirority_queue<pii,vector<pii>,greater<>> q;

// vector<int> dijkstra(int src){
//     vector<int> dist(N+1,INT_MAX);
//     q.push({0,src});
//     dist[src]=0;
    
//     while(!q.empty()){
//         int u=q.top().second;
//         int src_u=q.top().first;
//         q.pop();
        
//         if(src_u>dist[u]) continue;
        
//         for(int i=0;i<g[u].size();i++){
//             int v=g[u][i].fisrt;
//             int u_v=g[u][i].second;
            
//             if(src_u+u_v<dist[v]){
//                 dist[v]=src_u+u_v;
//                 q.push({dist[v],v});
//             }
//         }
//     }
    
//     return dist;
// }

void floyd(){
    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(dist[i][k]==INT_MAX||dist[k][j]==INT_MAX) continue;
                if(dist[i][k]+dist[k][j]<dist[i][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    N=n, S=s,A=a,B=b;
    E=fares.size();
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++){
        dist[i][j]=INT_MAX;
        if(i==j) dist[i][j]=0;
    }
    for(int i=0;i<E;i++){
        int u=fares[i][0],v=fares[i][1],w=fares[i][2];
        dist[u][v]=w;
        dist[v][u]=w;
        
        // g[u].push_back({v,w});
        // g[v].push_back({u,w});
    }
    
    floyd();
    ll ans=dist[S][A]+dist[S][B];
    // assert(dist[S][A]==dist[A][S]);
    // assert(dist[S][B]==dist[B][S]);
    for(int i=1;i<=N;i++){
        ll src_i=dist[S][i];
        ll i_A=dist[i][A];
        ll i_B=dist[i][B];
        // cout<<"i: "<<i<<endl;
        
        if(i_A==INT_MAX||i_B==INT_MAX||src_i==INT_MAX) continue;
        
        ll sum=i_A+i_B+src_i;
        // cout<<"src_i: "<<src_i<<" i_A: "<<i_A<<" i_B: "<<i_B<<" sum: "<<sum<<endl;
        ans=min(ans,sum);
    }
    
    
    int answer = ans;
    return answer;
}