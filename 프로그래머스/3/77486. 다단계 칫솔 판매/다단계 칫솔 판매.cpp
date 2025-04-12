#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <climits>
#include <cmath>
#include <cassert>
#include <iostream>
#include <unordered_map>
using namespace std;
typedef pair<int,int> pii;

int parent[10001];
string Idx2name[10001];
unordered_map<string,int> name2Idx;
int N,M;
int sum[10001];

void divide(int cur,int w){
    
    int nw=w/10;
    sum[cur]+=w-nw;
    // cout<<"cur: "<<Idx2name[cur]<<" w-nw: "<<w-nw<<" sum[cur]: "<<sum[cur]<<endl;
    if(nw>0&&parent[cur]!=-1) divide(parent[cur],nw);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    //init
    N=enroll.size();
    M=seller.size();
    for(int i=0;i<N;i++){
        string name=enroll[i];
        name2Idx[name]=i;
        Idx2name[i]=name;
    }
    memset(parent,-1,sizeof(parent));
    for(int i=0;i<N;i++){
        string pname=referral[i];
        if(pname=="-") continue;
        parent[i]=name2Idx[pname];
    }
    
    //solve
    for(int i=0;i<M;i++){
        int idx=name2Idx[seller[i]];
        int w=amount[i]*100;
        
        // cout<<"idx: "<<idx<<" w: "<<w<<endl;
        divide(idx,w);
    }
    
    
    vector<int> answer;
    for(int i=0;i<N;i++){
        answer.push_back(sum[i]);
    }
    return answer;
}