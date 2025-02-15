#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <climits>
#include <cassert>
#include <iostream>
#include <cmath>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
typedef long long int ll;
#define endl '\n'

vector<string> map;
vector<string> map_copy;
vector<pii> v[27];
vector<pii> v_copy[27];
int N,M;

int chk[51][51];
int chk_copy[51][51]; //외곽인 애들 체크
int way[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int ans=0;

queue<pii> q;

void chkOutLine(){//외곽인 애들 chk처리해주기
    memset(chk,0,sizeof(chk));
    
    //시작 부분들 q에 넣기
    int y=0,x=0,w=1;
    while(1){
        int ny=y+way[w][0],nx=x+way[w][1];
        if(ny<0||nx<0||ny>=N||nx>=M){
            w=(w+1)%4; continue;
        }
        
        //처리
        int c=map[y][x]-'A';
        chk[y][x]=1;
        q.push({y,x});
        
        y=ny,x=nx;
        if(y==0&&x==0) break;//다음이 0,0이면 끝
    }
    
    while(!q.empty()){
        y=q.front().first;
        x=q.front().second;
        q.pop();
        
        if(map[y][x]!='a') continue;
        
        //내가 죽었다면, 주위애들도 외곽
        for(int w=0;w<4;w++){
            int ny=y+way[w][0];
            int nx=x+way[w][1];
            if(ny>=0&&nx>=0&&ny<N&&nx<M&&chk[ny][nx]==0){//죽었든, 안죽었든 ny,nx는 외곽
                chk[ny][nx]=1;
                q.push({ny,nx});
            }
        }
    }
}

void removeOutline(int c){
    char cc=c+'A';
    chkOutLine();
    
    for(int i=0;i<N;i++)for(int j=0;j<M;j++){
        int y=i,x=j;
        if(map[y][x]==cc){
            if(chk[y][x]){
                map[y][x]='a';
                ans--;
                // cout<<"y: "<<y<<" x: "<<x<<endl;
            }
        }
    }
}

void removeAll(int c){
    char cc=c+'A';
     for(int i=0;i<N;i++)for(int j=0;j<M;j++){
        int y=i,x=j;
        if(map[y][x]==cc){
            map[y][x]='a';
            ans--;
            // cout<<"y: "<<y<<" x: "<<x<<endl;
        }
     }
}

int solution(vector<string> storage, vector<string> requests) {
    //init
    map=storage; N=map.size(), M=map[0].size();
    int y=0,x=0,w=1;
    ans=N*M;
    
    
    //solve
    for(string order:requests){
        int c=order[0]-'A';
        // cout<<"order: "<<order<<endl;
        if(order.size()==1) removeOutline(c);
        else removeAll(c);
    }
    
    
    int answer = ans;
    return answer;
}