#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <climits>
#include <cassert>
#include <cmath>
#include <iostream>
using namespace std;
int N,M,K;
int arr[51][51];
int way[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int y,x;

int wtoi(char w){
    if(w=='N') return 0;
    if(w=='E') return 1;
    if(w=='S') return 2;
    return 3;
}

void move(int d,int k){
    int ny=y,nx=x;
    for(int i=0;i<k;i++){
        ny=ny+way[d][0];
        nx=nx+way[d][1];
        // cout<<"y: "<<y<<" x: "<<x<<" ny: "<<ny<<" nx: "<<nx<<endl;
        if(ny>=0&&nx>=0&&ny<N&&nx<M&&arr[ny][nx]==0){
            
        }
        else return;
    }
    y=ny; x=nx;
}

vector<int> solution(vector<string> park, vector<string> routes) {
    N=park.size();
    M=park[0].size();
    for(int i=0;i<N;i++)for(int j=0;j<M;j++){
        if(park[i][j]=='S'){
            arr[i][j]=0; y=i; x=j;
        }
        else if(park[i][j]=='O') arr[i][j]=0;
        else if(park[i][j]=='X') arr[i][j]=1;
    }
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<M;j++) cout<<arr[i][j]<<" ";
    //     cout<<endl;
    // }
    // cout<<"x: "<<x<<" y: "<<y<<endl;
    
    K=routes.size();
    for(int i=0;i<K;i++){
        char w=routes[i][0];
        int k=routes[i][2]-'0';
        int d=wtoi(w);
        // cout<<"k: "<<k<<" d: "<<d<<endl;
        move(d,k);
    }
    
    vector<int> answer;
    answer.push_back(y);
    answer.push_back(x);
    return answer;
}