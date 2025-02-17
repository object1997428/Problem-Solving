#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <climits>
#include <iostream>
#include <cmath>
#include <cassert>
#include <queue>
#define endl '\n'
using namespace std;
typedef pair<int,int> pii;
typedef long long int ll;

vector<pii> card[9];
vector<int> character;
vector<vector<int>> arr;

vector<int> cardOrder;
int sy,sx,ans;
queue<pii> q;
int chk[5][5];
int way[4][2]={{-1,0},{0,1},{1,0},{0,-1}};

vector<int> wv;
pii moveCtrl(int y,int x,int w){
    //ctrl+동서남북
    int ny=y,nx=x;
    int canMove=1;
    for(int i=0;i<4;i++){
        ny+=way[w][0], nx+=way[w][1];
        if(ny<0||nx<0||ny>=4||nx>=4){
            if(i==0) {canMove=0; return {-1,-1};}
            else { ny-=way[w][0], nx-=way[w][1]; return {ny,nx};}
        }
        else if(arr[ny][nx]>0) return {ny,nx};
    }
    return {-1,-1};
}


int getMindist(int sy,int sx,int ey,int ex){
    //두 카드를 최단거리로 가고, 최단거리 반환
    wv.clear();
    memset(chk,0,sizeof(chk));
    while(!q.empty()) q.pop();
    
    q.push({sy,sx});
    chk[sy][sx]=1;
    
    
    if(sy<ey) wv.push_back(2);
    else if(sy>ey) wv.push_back(0);
    if(sx<ex) wv.push_back(1);
    else if(sx>ex) wv.push_back(3);
    
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        
        if(y==ey&&x==ex) return chk[y][x]-1;
        
        for(int w:wv){
            //그냥 가기
            int ny=y+way[w][0],nx=x+way[w][1];
            if(ny>=0&&nx>=0&&ny<4&&nx<4&&chk[ny][nx]==0){
                chk[ny][nx]=chk[y][x]+1;
                q.push({ny,nx});
            }
            
            //ctrl+w
            pii ret=moveCtrl(y,x,w);
            ny=ret.first,nx=ret.second;
            if(ny>=0&&nx>=0&&ny<4&&nx<4&&chk[ny][nx]==0){
                chk[ny][nx]=chk[y][x]+1;
                q.push({ny,nx});
            }
        }
    }
    
    return -1;
}

int simulate(){
    int cy=sy,cx=sx;
    int sum=0;
    for(int i=0;i<character.size();i++){
        int num=character[i];
        pii card1=card[num][0];
        pii card2=card[num][1];
        if(cardOrder[num-1]!=0) swap(card1,card2);
        
        int cursor_card1=getMindist(cy,cx,card1.first,card1.second);
        int card1_card2=getMindist(card1.first,card1.second,card2.first,card2.second);
        sum+=cursor_card1+card1_card2+2;
        
        arr[card1.first][card1.second]=0;
        arr[card2.first][card2.second]=0;
        
        cy=card2.first, cx=card2.second;
        
        if(ans<sum) break;
    }
    
    
     for(int i=0;i<character.size();i++){
        int num=character[i];
        pii card1=card[num][0];
        pii card2=card[num][1];
        arr[card1.first][card1.second]=num;
        arr[card2.first][card2.second]=num;
     }
    
    return sum;
}

void pick(int cnt){
    if(cnt==character.size()){
        
        int ret=simulate();
        // cout<<"ret: "<<ret<<endl;
        ans=min(ans,ret);
        return;
    }
    for(int i=0;i<=1;i++){
        cardOrder.push_back(i);
        pick(cnt+1);
        cardOrder.pop_back();
    }
}

int solution(vector<vector<int>> board, int r, int c) {
    //init
    arr=board;
    ans=INT_MAX; sy=r, sx=c;
    for(int i=0;i<4;i++)for(int j=0;j<4;j++){
        if(arr[i][j]>0){
            int num=arr[i][j];
            if(card[num].empty()) character.push_back(num);
            card[num].push_back({i,j});
        }
    }
    
    //solve
    sort(character.begin(),character.end());
    do{
        pick(0);
        
    }while(next_permutation(character.begin(),character.end()));
    
    int answer = ans;
    return answer;
}