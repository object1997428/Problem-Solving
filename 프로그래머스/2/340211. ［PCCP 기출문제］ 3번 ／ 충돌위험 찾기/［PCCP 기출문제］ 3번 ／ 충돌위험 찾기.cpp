#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <climits>
#include <cassert>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

vector<vector<int>> points,routes;
vector<vector<int>> v;
int N,M;//N;로봇개수, M:라우터 개수
int way[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int dead[101];
int deadSize;
int arr[101][101];
pii robots[101];
int t;

int simulate(){
    int count=0;
    for(int i=0;i<101;i++)for(int j=0;j<101;j++){
            if(arr[i][j]>1){
                count++;
                // cout<<"count-- time: "<<t<<" i: "<<i<<" j: "<<j<<endl;
            } 
            
        }
    while(1){
        //초당
        
        for(int i=0;i<N;i++){
            if(dead[i]==1) continue;
            int y=robots[i].first, x=robots[i].second;
            if(v[i].size()<=t){
                // cout<<"t: "<<t<<endl;
                dead[i]=1; deadSize++;
                arr[y][x]--;
                continue;
            }
            
            //안도착한 로봇들은 한칸씩 움직이기
            int w=v[i][t];
            
            int ny=y+way[w][0], nx=x+way[w][1];
            
            robots[i]={ny,nx};
            arr[y][x]--;
            arr[ny][nx]++;
            
            // cout<<"time: "<<t<<" robot: "<<i<<" w: "<<w<<" ny: "<<ny<<" nx: "<<nx<<" arr[y][x]: "<<arr[y][x]<<" arr[ny][nx]: "<<arr[ny][nx]<<endl;
        }
        
        for(int i=0;i<101;i++)for(int j=0;j<101;j++){
            if(arr[i][j]>1){
                count++;
                // cout<<"count-- time: "<<t<<" i: "<<i<<" j: "<<j<<endl;
            } 
            
        }
        
        
        ++t;
        if(deadSize>=N) return count;
    }
}

int solution(vector<vector<int>> _points, vector<vector<int>> _routes) {
    //init
    points=_points; routes=_routes;
    N=routes.size(),M=points.size();
    // cout<<"N: "<<N<<" M: "<<M<<endl;
    
    
    //solve
    //로봇마다 가야하는 방향 미리 다 넣어놓기
    
    for(int i=0;i<N;i++){//로봇당
        vector<int> tmp;
        
        int first=routes[i][0]-1;
        int sy=points[first][0],sx=points[first][1];
        robots[i]={sy,sx};
        arr[sy][sx]++;
        for(int j=1;j<routes[0].size();j++){//찾아가야하는 포인트
            
            // cout<<"i: "<<i<<" j: "<<j<<endl;
            int pre=routes[i][j-1]-1, next=routes[i][j]-1;
            // cout<<"pre: "<<pre<<" next: "<<next<<endl;
            int py=points[pre][0]; int px=points[pre][1];
            int ny=points[next][0]; int nx=points[next][1];
            
            if(py>ny){//위로 가야됨
                for(int k=0;k<py-ny;k++) {
                    tmp.push_back(0);
                }
            }
            else if(py<ny){//아래로 가야됨
                for(int k=0;k<abs(py-ny);k++) tmp.push_back(2);
                assert(abs(py-ny)>=0);
            }
            
            if(px>nx){//왼쪽로 가야됨
                for(int k=0;k<px-nx;k++) tmp.push_back(3);
            }
            else if(px<nx){//오른쪽로 가야됨
                for(int k=0;k<abs(px-nx);k++) tmp.push_back(1);
            }
        }
        v.push_back(tmp);
        // for(auto xx:tmp)cout<<xx<<" "; cout<<endl;
        // cout<<"v[i].size(): "<<v[i].size()<<endl;
    }
    
    
    
    int answer = simulate();
    return answer;
}