#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <climits>
#include <cassert>
#include <cmath>
#include <iostream>
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int> pip;

vector<pip> info; //{{y,x},num};
vector<int> node[1002]; //[depth]=info.인덱스
pii child[10001];//[v]={l,r};
int N,maxDepth;
vector<int> ans1,ans2;

void makeTree(int curIdx,int l,int r,int d){
    // if(d==maxDepth) return;
    
    for(int i=0;i<node[d+1].size();i++){
        int nextIdx=node[d+1][i];//depth+1인 i번째 infoIdx
        int next=info[nextIdx].second;
        if(l<info[nextIdx].first.second&&info[nextIdx].first.second<r){
            if(info[nextIdx].first.second<info[curIdx].first.second){//next.x<cur.x
                child[curIdx].first=nextIdx;//cur의 왼쪽자식=next
                // cout<<"cur: "<<info[curIdx].second<<" leftChild: "<<info[nextIdx].second<<endl;
                makeTree(nextIdx,l,info[curIdx].first.second,d+1);//next는 l,cur.x의 범위를 가진다
            } 
            else if(info[nextIdx].first.second>info[curIdx].first.second){
                child[curIdx].second=nextIdx;//cur의 오른쪽자식=next
                // cout<<"cur: "<<info[curIdx].second<<" rightChild: "<<info[nextIdx].second<<endl;
                makeTree(nextIdx,info[curIdx].first.second,r,d+1);
            } 
            else{
                // assert(0);
            }
        }
    }
}

void dfs1(int curIdx){
    ans1.push_back(info[curIdx].second);
    if(child[curIdx].first!=-1) dfs1(child[curIdx].first);
    if(child[curIdx].second!=-1) dfs1(child[curIdx].second);
}

void dfs2(int curIdx){
    if(child[curIdx].first!=-1) dfs2(child[curIdx].first);
    if(child[curIdx].second!=-1) dfs2(child[curIdx].second);
    ans2.push_back(info[curIdx].second);
}



vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    for(int i=0;i<nodeinfo.size();i++){
        int x=nodeinfo[i][0];
        int y=nodeinfo[i][1];
        info.push_back({{y,x},i+1});
    }
    sort(info.begin(),info.end(),greater<>());
    int depth=-1,curY=100001;
    int rootIdx=-1;
    memset(child,-1,sizeof(child));
    for(int i=0;i<info.size();i++){
        if(curY>info[i].first.first){//info[i].y
            curY=info[i].first.first; //info[i].y
            depth++;
        }
        node[depth].push_back(i);
    }
    rootIdx=node[0][0];//depth=0인, infoIdx
    // cout<<"root: "<<rootIdx<<" info[root]: "<<info[rootIdx].second<<endl;
    // root=info[root].second;
    maxDepth=depth;
    
    makeTree(rootIdx,-1,100001,0);
    dfs1(rootIdx);
    dfs2(rootIdx);
    vector<vector<int>> answer;
    answer.push_back(ans1);
    answer.push_back(ans2);
    
    
    return answer;
}