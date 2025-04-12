#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <climits>
#include <cmath>
#include <cassert>
#include <iostream>
using namespace std;
typedef pair<int,int> pii;

int N,M,Q;
int arr[101][101];
int way[4][2]={{-1,0},{0,1},{1,0},{0,-1}};

int rotate(int y1,int x1,int y2,int x2){
    int y=y1,x=x1, w=1;
    int curV=arr[y][x];
    
    int minV=curV;
    
    // int count=10;
    // cout<<"y1: "<<y1<<" x1: "<<x1<<"  y2: "<<y2<<" x2: "<<x2<<endl;
    while(1){
        int ny=y+way[w][0], nx=x+way[w][1];
        if(ny<y1||nx<x1||ny>y2||nx>x2){
            w=(w+1)%4;
            continue;
        }
        
        // cout<<"ny: "<<ny<<" nx: "<<nx<<endl;
        int tmp=arr[ny][nx];
        arr[ny][nx]=curV;
        curV=tmp;
        minV=min(minV,curV);
        minV=min(minV,tmp);
        
        if(ny==y1&&nx==x1) break;
        
        y=ny,x=nx;
    }
    
    return minV;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    //init
    N=rows,M=columns;
    Q=queries.size();
    int num=1;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            arr[i][j]=num++;
        }
    }
    
//      for(int i=0;i<N;i++){
//             for(int j=0;j<M;j++) {cout<<arr[i][j]<<" ";}
//             cout<<endl;
//         } cout<<endl;
    
    //solve
    vector<int> answer;
    for(int i=0;i<Q;i++){
        int y1=queries[i][0]-1;
        int x1=queries[i][1]-1;
        int y2=queries[i][2]-1;
        int x2=queries[i][3]-1;
        
        int ret=rotate(y1,x1,y2,x2);
        answer.push_back(ret);
        
//         for(int i=0;i<N;i++){
//             for(int j=0;j<M;j++) {cout<<arr[i][j]<<" ";}
//             cout<<endl;
//         } cout<<endl;
    }
    
    

    return answer;
}