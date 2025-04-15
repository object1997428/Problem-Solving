#include <string>
#include <vector>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <cassert>
#include <unordered_map>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int,int> pii;

int tCnt;
int i2t[400001];
int N,E;
vector<int> g[400001];
int chk[400001][2];//트리 t가 홀짝이다: chk[t][0]=1, 역홀짝트리다 chk[t][1]=1

vector<int> v;
unordered_map<int,int> m1;
int i2pre[400001];

void setTree(int cur,int pre,int t){
    // cout<<"t: "<<t<<" cur: "<<cur<<endl;
    i2t[cur]=t;
    
    for(int i=0;i<g[cur].size();i++){
        int next=g[cur][i];
        if(next!=pre){
            setTree(next,cur,t);
        }
    }
}

bool check0(int cur,int pre){
    // cout<<"i2pre[cur]: "<<i2pre[cur]<<" (g[cur].size()-1): "<<(g[cur].size()-1)<<endl;
    if(i2pre[cur]%2!=(g[cur].size()-1)%2){
        return false;
    }

    for(int i=0;i<g[cur].size();i++){
        int next=g[cur][i];
        if(next!=pre){
            if(check0(next,cur)==false) return false;
        }
    }
    return true;
}

bool check1(int cur,int pre){
    // cout<<"i2pre[cur]: "<<i2pre[cur]<<" (g[cur].size()-1): "<<(g[cur].size()-1)<<endl;
    if(i2pre[cur]%2==(g[cur].size()-1)%2){
        return false;
    }
    
    for(int i=0;i<g[cur].size();i++){
        int next=g[cur][i];
        if(next!=pre){
            if(check1(next,cur)==false) return false;
        }
    }
    return true;
}

vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
    //init
    N=nodes.size(), E=edges.size();
    //좌표 압축
    for(int i=0;i<N;i++){
        v.push_back(nodes[i]);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<N;i++){
        int idx=lower_bound(v.begin(),v.end(),v[i])-v.begin();
        m1[v[i]]=idx;
        i2pre[idx]=v[i];
        // cout<<"v[i]: "<<v[i]<<" idx: "<<idx<<endl;
    }
    
    //그래프 세팅
    for(int i=0;i<E;i++){
        int u=edges[i][0], v=edges[i][1];
        int u2=m1[u], v2=m1[v];
        g[u2].push_back(v2);
        g[v2].push_back(u2);
    }
    //트리끼리 묶기
    memset(i2t,-1,sizeof(i2t));
    for(int i=0;i<N;i++){
        if(i2t[i]==-1){
            setTree(i,-1,tCnt++);
        }
    }
    
    //solve
    int cnt0=0, cnt1=0;
    for(int i=0;i<N;i++){
        int t=i2t[i];
        // cout<<"i2pre[cur]: "<<i2pre[i]<<" t: "<<t<<endl;
        if(chk[t][0]==0&&(g[i].size()%2==i2pre[i]%2)){
            int flag=1;
            for(int j=0;j<g[i].size();j++){
                int child=g[i][j];
                int ret=check0(child,i);
                if(ret==0){
                    flag=0; break;
                }
            }
            if(flag==1){
                // cout<<"0-- i2pre[cur]: "<<i2pre[i]<<" t: "<<t<<endl;
                chk[t][0]=1;
            }
        }
        if(chk[t][1]==0&&(g[i].size()%2!=i2pre[i]%2)){
            int flag=1;
            for(int j=0;j<g[i].size();j++){
                int child=g[i][j];
                int ret=check1(child,i);
                if(ret==0){
                    flag=0; break;
                }
            }
            if(flag==1){
                // cout<<"1-- i2pre[cur]: "<<i2pre[i]<<" t: "<<t<<endl;
                chk[t][1]=1;
            }
        }
    }
    
    for(int i=0;i<tCnt;i++){
        if(chk[i][0]==1) cnt0++;
        if(chk[i][1]==1) cnt1++;
    }
    
    
    vector<int> answer;
    answer.push_back(cnt0);
    answer.push_back(cnt1);
    return answer;
}