#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cmath>
#include <cassert>
#include <queue>
using namespace std;
typedef pair<int,int> pii;

vector<pii> cardpair[9]; //[num]<- pii, pii
int arr[4][4];
int way[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int cy,cx;

//캐릭터 없애는 순서 고르기 dfs
vector<int> pickedV; //캐릭터 num
int picked[9];

vector<int> wv;
queue<pii> q;
int visited[4][4];
vector<int> startdec;

pii moveCtrl(int y,int x,int w){
    int ny=y,nx=x;
    for(int i=0;i<4;i++){
        ny=ny+way[w][0];
        nx=nx+way[w][1];
        if(ny<0||nx<0||ny>=4||nx>=4){//범위밖
            if(i==0) return {-1,-1}; //갈 수 없다
            else{ //마지막 벽으로 이동
                ny=ny-way[w][0];
                nx=nx-way[w][1];
                return {ny,nx};
            }
        }
        else{//범위 안
            //카드 만났으면
            if(arr[ny][nx]>0) return {ny,nx};
        }
    }
    return {-1,-1};
}


int mindist(int sy,int sx,int ey,int ex){
    memset(visited,0,sizeof(visited));
    while(!q.empty()) q.pop();
    
    q.push({sy,sx});
    visited[sy][sx]=1; //나중에 return -1
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();

        if(y==ey&&x==ex){
            return visited[y][x]-1;
        } 
        
        //방향 정하기
        wv.clear();
        if(y>ey) wv.push_back(0);
        else if(y<ey) wv.push_back(2);
        if(x>ex) wv.push_back(3);
        else if(x<ex) wv.push_back(1);
        
        for(int w:wv){
            //ctrl
            pii next=moveCtrl(y,x,w);
            int ny=-1,nx=-1;
            if(next.first!=-1){
                ny=next.first, nx=next.second;
                if(visited[ny][nx]==0){
                    q.push({next.first,next.second});
                    visited[ny][nx]=visited[y][x]+1;
                }
            }
            
            //그냥
            ny=y+way[w][0];
            nx=x+way[w][1];
            // cout<<"y: "<<y<<" x: "<<x<<" ny: "<<ny<<" nx: "<<nx<<endl;
            if(ny>=0&&nx>=0&&ny<4&&nx<4&&visited[ny][nx]==0){
                // cout<<"y: "<<y<<" x: "<<x<<" ny: "<<ny<<" nx: "<<nx<<endl;
                q.push({ny,nx});
                visited[ny][nx]=visited[y][x]+1;
            }
        }
    }
    return -1;
}


int ans;
int simulate(){
    int sy=cy,sx=cx;
    
    int dist=0;
    // cout<<"start--"<<endl;
    // cout<<"sy: "<<sy<<" sx: "<<sx<<endl;
    for(int num:pickedV){
        // num캐릭터 카드 없애기
        pii card1=cardpair[num][0];
        pii card2=cardpair[num][1];
        if(startdec[num-1]!=0) swap(card1,card2);
        
        
        //1. 최소 횟수 구하기
        int s_card1=mindist(sy,sx,card1.first,card1.second);
        int card1_card2=mindist(card1.first,card1.second,card2.first,card2.second);
        
        assert(s_card1!=-1&&card1_card2!=-1);
        
        // cout<<"sy: "<<sy<<" sx: "<<sx<<" card1.first: "<<card1.first<<" card1.second: "<<card1.second<<" card2.first: "<<card2.first<<" card2.second: "<<card2.second<<endl;
        // cout<<"s_card1: "<<s_card1<<" card1_card2: "<<card1_card2<<" / s_card2: "<<s_card2<<" card2_card1: "<<card2_card1<<endl;
        dist+=s_card1+card1_card2+2;
            sy=card2.first;
            sx=card2.second;
        // cout<<"dist: "<<dist<<endl;
        
        if(ans<dist) break;
        
        //2. 카드 지우기
        arr[card1.first][card1.second]=0;
        arr[card2.first][card2.second]=0;
    }
    
    //시뮬 끝내고 다시 복구
    
    for(int num:pickedV){
        pii card1=cardpair[num][0];
        pii card2=cardpair[num][1];
        
        arr[card1.first][card1.second]=num;
        arr[card2.first][card2.second]=num;
    }
    
    // cout<<"dist: "<<dist<<endl;

    
    return dist;
}

void pick(int cnt,int maxnum){
    if(cnt==maxnum){
        int dist=simulate();
        ans=min(ans,dist);
        return;
    }
    for(int i=0;i<=1;i++){
        startdec.push_back(i);
        pick(cnt+1,maxnum);
        startdec.pop_back();
    }
}


int solution(vector<vector<int>> board, int r, int c) {
    //init
    cy=r,cx=c;
    ans=INT_MAX;
    
    int maxnum=1;
    for(int i=0;i<4;i++)for(int j=0;j<4;j++){
        int num=board[i][j];
        arr[i][j]=num;
        cardpair[num].push_back({i,j});
        maxnum=max(maxnum,num);
    }
    
    for(int i=1;i<=maxnum;i++) {
        pickedV.push_back(i);
        // cout<<"i: "<<i<<endl;
    }
    do{
        pick(0,maxnum);
        
    }while(next_permutation(pickedV.begin(),pickedV.end()));
    
    
    int answer = ans;
    return answer;

}