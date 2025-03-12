#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <climits>
#include <cmath>
#include <cassert>
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define endl '\n'

int arr[104][104];
int road[104][104];
int way[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int way2[8][2]={{-1,0},{0,1},{1,0},{0,-1},{-1,-1},{-1,1},{1,1},{1,-1}};

int N,M,ey,ex;
int ans;
int chk[104][104],chk2[104][104];
queue<pii> q;
void bfs(){
    
    //테두리 0인애들 집어넣기
    for(int i=0;i<=102;i++){
        q.push({i,0});
        chk[i][0]=1;
    }
    for(int i=0;i<=102;i++){
        q.push({0,i});
        chk[0][i]=1;
    }
    
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();//바깥 0인 y,x만 담음
        
        for(int w=0;w<8;w++){
            int ny=y+way2[w][0], nx=x+way2[w][1];
            if(ny>=2&&nx>=2&&ny<=100&&nx<=100&&chk[ny][nx]==0&&arr[ny][nx]>=1&&road[ny][nx]==0){
                chk[ny][nx]=1;
                road[ny][nx]=1;
                // cout<<"y: "<<ny/2<<" x: "<<nx/2<<endl;
            }
            else if(ny>=0&&nx>=0&&ny<=102&&nx<=102&&chk[ny][nx]==0){
                chk[ny][nx]=1;
                q.push({ny,nx});
            }
        }
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int sx=characterX,sy=characterY;
    ex=itemX, ey=itemY;
    
    //1. 직사각형 포함된 칸 +1
    for(int i=0;i<rectangle.size();i++){
        int ax=rectangle[i][0]*2,ay=rectangle[i][1]*2;
        int bx=rectangle[i][2]*2,by=rectangle[i][3]*2;
        
        for(int j=0;j<=by-ay;j++)for(int k=0;k<=bx-ax;k++){
            arr[ay+j][ax+k]++;
        }
        N=min(N,ay);
        N=min(N,by);
        M=min(M,ax);
        M=min(M,bx);
    }
    
    // for(int i=0;i<22;i++){
    //     for(int j=0;j<22;j++){
    //         cout<<arr[i][j]<<" ";
    //     }cout<<endl;
    // }
    
    //2. 0이랑 맞닿아있는 애들 체크
    bfs();
    // for(int i=0;i<=102;i++)for(int j=0;j<=102;j++){
    //     if(arr[i][j]==0){
    //         for(int w=0;w<8;w++){
    //             int ny=i+way2[w][0], nx=j+way2[w][1];
    //             if(ny>=1&&nx>=1&&ny<=50&&nx<=50&&arr[ny][nx]>0&&road[ny][nx]==0){
    //                 road[ny][nx]=1;
    //                 // cout<<"y: "<<ny/2<<" x: "<<nx/2<<endl;
    //             }
    //         }
    //     }
    // }
    
    memset(chk,0,sizeof(chk));
    
    // cout<<"arr[sy][sx]: "<<arr[sy][sx]<<" arr[ey][ex]: "<<arr[ey][ex]<<endl;
    // for(int i=0;i<11;i++){
    //     for(int j=0;j<11;j++){
    //         cout<<road[i][j]<<" ";
    //     }cout<<endl;
    // }
    
    vector<pii> v;
    int y=sy*2,x=sx*2, w=0;
    int ans=0;
    
    int cnt=0;
    while(1){
        int ny=y+way[w][0], nx=x+way[w][1];
        if(ny<2||nx<2||ny>100||nx>100||road[ny][nx]!=1||chk[ny][nx]!=0){
            w=(w+1)%4; continue;
        }
        
        chk[ny][nx]=1;
        y=ny,x=nx;
        
        if(ny%2==0&&nx%2==0&&chk2[ny/2][nx/2]==0&&ny>=2&&nx>=2&&ny<=100&&nx<=100){
            // cout<<"ny: "<<ny/2<<" nx: "<<nx/2<<endl;
            chk2[ny/2][nx/2]=1;
            cnt++;
        }
        if(y==ey*2&&x==ex*2) ans=cnt; //(s,e]
        
        if(y==sy*2&&x==sx*2) break;
    }
    
    //3. bfs로 최단거리 구하기
    int pre=ans;
    // cout<<"road[6][4]: "<<road[6][4]<<endl;
    // cout<<"cnt: "<<cnt<<" pre: "<<pre<<endl;
    ans=min(ans,cnt-pre);
    
    
    int answer = ans;
    return answer;
}