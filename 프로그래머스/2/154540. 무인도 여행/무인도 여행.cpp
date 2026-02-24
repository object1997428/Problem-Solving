#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <climits>
#include <cassert>
#include <cmath>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define endl '\n'

vector<string> maps;
int N,M,cnt;
int chked[101][101];
queue<pii> q1;
int way[4][2]={{-1,0},{0,1},{1,0},{0,-1}};

int bfs(int sy,int sx){
    ++cnt;
    // cout<<"cnt: "<<cnt<<endl;
    
    int sum=maps[sy][sx]-'0';
    chked[sy][sx]=cnt;
    q1.push({sy,sx});
    
    while(!q1.empty()){
        int y=q1.front().first, x=q1.front().second;
        q1.pop();
        
        for(int w=0;w<4;w++){
            int ny=y+way[w][0];
            int nx=x+way[w][1];
            if(ny>=0&&nx>=0&&ny<N&&nx<M&&chked[ny][nx]==0&&maps[ny][nx]!='X'){
                sum+=maps[ny][nx]-'0';
                // cout<<"maps[ny][nx]-'0': "<<maps[ny][nx]-'0'<<" sum: "<<sum<<endl;
                chked[ny][nx]=cnt;
                q1.push({ny,nx});
            }
        }
    }
    
    return sum;
}

vector<int> solution(vector<string> _maps) {
    maps=_maps;
    N=maps.size(),M=maps[0].size();
    
    vector<int> answer;
    for(int i=0;i<N;i++)for(int j=0;j<M;j++){
        if(chked[i][j]==0&&maps[i][j]!='X'){
            int ret=bfs(i,j);
            
            answer.push_back(ret);
        }
    }
    if(answer.empty()) answer.push_back(-1);
    sort(answer.begin(),answer.end());
    
    
    return answer;
}