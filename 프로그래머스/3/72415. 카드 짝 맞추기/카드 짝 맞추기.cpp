#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <cassert>
#include <climits>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;

int arr[4][4];

int M;
vector<int> v;
vector<int> cardOrder;
pii card[9][2];

queue<pii> q;
int visited[4][4];
int way[4][2]={{-1,0},{0,1},{1,0},{0,-1}};

vector<int> wv;
int ans=INT_MAX;

pii goCtrl(int y,int x,int w){
    int canGo=1;
    int ny=y, nx=x;
    for(int i=0;i<4;i++){
        ny+=way[w][0], nx+=way[w][1];
        if(ny>=0&&nx>=0&&ny<4&&nx<4){
            if(arr[ny][nx]>0){
                return {ny,nx};
            }
        }
        else{//벽
            if(i==0){ return {-1,-1}; }
            else{
                ny-=way[w][0], nx-=way[w][1];
                return {ny,nx};
            }
        }
    }
    return {-1,-1};
}

int getMindist(int sy,int sx,int ey,int ex){
    memset(visited,0,sizeof(visited));
    while(!q.empty()) q.pop();
    q.push({sy,sx});
    visited[sy][sx]=1;
    
    wv.clear();
    if(sy<ey) wv.push_back(2);
    else if(sy>ey) wv.push_back(0);
    if(sx<ex) wv.push_back(1);
    else if(sx>ex) wv.push_back(3);
    
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        
        if(y==ey&&x==ex) return visited[y][x]-1;
        
        for(int k=0;k<wv.size();k++){
            int w=wv[k];
            //Ctrl
            pii ret=goCtrl(y,x,w);
            int ny=ret.first,nx=ret.second;
            if(ret.first!=-1){
                if(visited[ny][nx]==0){
                    visited[ny][nx]=visited[y][x]+1;
                    q.push({ny,nx});
                }
            }
            
            //그냥
            ny=y+way[w][0], nx=x+way[w][1];
            if(ny>=0&&nx>=0&&ny<4&&nx<4){
                if(visited[ny][nx]==0){
                    visited[ny][nx]=visited[y][x]+1;
                    q.push({ny,nx});
                }
            }
        }
    }
    return -1;
}

//정해진 캐릭터, 정해진 카드 순서대로 최단 거리 구하기
int solve(int cy,int cx){
    int ret=0;

    
    for(int i=0;i<M;i++){
        int c=v[i];
        int start=cardOrder[i];
        // cout<<"c: "<<c<<endl;

        pii src=card[c][start];
        pii dst=card[c][(start==0)?1:0];
        
        ret+=getMindist(cy,cx,src.first,src.second);
        ret+=getMindist(src.first,src.second,dst.first,dst.second);
        ret+=2;
        
        arr[src.first][src.second]=0;
        arr[dst.first][dst.second]=0;
        cy=dst.first; cx=dst.second;
        
        if(ans<ret) break;
    }
    
    for(int i=0;i<M;i++){
        int c=v[i];
        int start=cardOrder[i];
        pii src=card[c][start];
        pii dst=card[c][(start==0)?1:0];
        
        arr[src.first][src.second]=c;
        arr[dst.first][dst.second]=c;
    }
    
    return ret;
}

int solution(vector<vector<int>> board, int r, int c) {
    //init
    for(int i=0;i<4;i++)for(int j=0;j<4;j++) arr[i][j]=board[i][j];
    memset(card,-1,sizeof(card));
    
    for(int i=0;i<4;i++)for(int j=0;j<4;j++){
        int c=board[i][j];
        if(c>0){
            if(card[c][0].first==-1){
                card[c][0]={i,j};
                v.push_back(c);
            }
             else card[c][1]={i,j};
        }
    }
    
    //solve
    //캐릭터 순서 정하기
    sort(v.begin(),v.end());
    cardOrder.resize(v.size(),0);
    M=v.size();
    
    do{
        //캐릭터당 카드 순서 정하기
        for(int i=M-1;i>=0;i--) cardOrder[i]=0; //0으로 초기화
        
        int ret=solve(r,c);
        ans=min(ans,ret);
        for(int i=M-1;i>=0;i--){
            //00...001
            //00...011 이렇게 채우고, 순열시키기
            cardOrder[i]=1;
            do{
                ret=solve(r,c);
                ans=min(ans,ret);
            }while(next_permutation(cardOrder.begin(),cardOrder.end()));
        }
    }while(next_permutation(v.begin(),v.end()));
    
    
    int answer = ans;
    return answer;
}