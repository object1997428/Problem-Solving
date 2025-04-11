#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cassert>
#include <cmath>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int N;
int g[1001][1001],b[1001][1001];

bool check(int y,int x,int type){
    
    if(type==0){//기둥
        if(y==0) return true;
        else if(b[y][x]==1) return true;
        else if(x-1>=0&&b[y][x-1]==1) return true;
        else if(y-1>=0&&g[y-1][x]==1) return true;
        else {
            // cout<<"실패-- type: "<<type<<" y: "<<y<<" x: "<<x<<endl;
            return false;
        }
    }
    else{//보
        if(y-1>=0&&g[y-1][x]==1) return true;
        if(y-1>=0&&g[y-1][x+1]==1) return true;
        else if(x-1>=0&&x+1<N&&b[y][x-1]==1&&b[y][x+1]==1) return true;
        else{
            // cout<<"실패-- type: "<<type<<" y: "<<y<<" x: "<<x<<endl;
            return false;
        } 
    }
    // cout<<"check: 없는 케이스 발견"<<endl;
    return false;
}

void plusType(int y,int x,int type){
    if(!check(y,x,type)) return;
    if(type==0) {
        g[y][x]=1; //기둥
        // cout<<"plus 성공-- type: "<<type<<" y: "<<y<<" x: "<<x<<endl;
        // cout<<"g[y][x]: "<<g[y][x]<<endl;
    }
    else {
        b[y][x]=1; //보
        // cout<<"plus 성공-- type: "<<type<<" y: "<<y<<" x: "<<x<<endl;
        // cout<<"b[y][x]: "<<b[y][x]<<endl;
    }
}

void minusType(int y,int x,int type){
    if(type==0){//기둥
        g[y][x]=0;
        
        if(y+1<N&&g[y+1][x]==1&&check(y+1,x,0)==0) {
            g[y][x]=1;
            return;
        }
        if(y+1<N&&b[y+1][x]==1&&check(y+1,x,1)==0){
            g[y][x]=1;
            return;
        }
        if(y+1<N&&x-1>=0&&b[y+1][x-1]==1&&check(y+1,x-1,1)==0){
            g[y][x]=1;
            return;
        }
        if(b[y][x]==1&&check(y,x,1)==0){
            g[y][x]=1;
            return;
        }
        if(x-1>=0&&b[y][x-1]==1&&check(y,x-1,1)==0){
            g[y][x]=1;
            return;
        }
        if(y-1>=0&&g[y-1][x]==1&&check(y-1,x,0)==0){
            g[y][x]=1;
            return;
        }
        // cout<<"minus 성공-- type: "<<type<<" y: "<<y<<" x: "<<x<<endl;
        // g[y][x]=0;
    }
    else{//보
        b[y][x]=0;
        
        if(g[y][x]==1&&check(y,x,0)==0){
            b[y][x]=1;
            return;
        }
        if(x+1<N&&g[y][x+1]==1&&check(y,x+1,0)==0){
            b[y][x]=1;
            return;
        }
        if(x-1>=0&&b[y][x-1]==1&&check(y,x-1,1)==0){
            b[y][x]=1;
            return;
        }
        // cout<<"b[y][x+1]: "<<b[y][x+1]<<endl;
        if(x+1<N&&b[y][x+1]==1&&check(y,x+1,1)==0){
            b[y][x]=1;
            return;
        }
        if(y-1>=0&&g[y-1][x]==1&&check(y-1,x,0)==0) {
            b[y][x]=1;
            return;
        }
        if(x+1<N&&y-1>=0&&g[y-1][x+1]==1&&check(y-1,x+1,0)==0) {
            b[y][x]=1;
            return;
        }
        // cout<<"minus 성공-- type: "<<type<<" y: "<<y<<" x: "<<x<<endl;
        // b[y][x]=0;
    } 
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    N=n;
    for(auto o:build_frame){
        int y=o[1];
        int x=o[0];
        int type=o[2], isPlus=o[3];
        // cout<<"y: "<<y<<" x: "<<x<<" type: "<<type<<" isPlus: "<<isPlus<<endl;
        if(isPlus){//설치
            plusType(y,x,type);
        }
        else{//삭제
            minusType(y,x,type);
        }
    }
    
    
    vector<vector<int>> answer;
    for(int i=0;i<1001;i++){
        for(int j=0;j<1001;j++){
            if(g[j][i]==1) answer.push_back({i,j,0});
            if(b[j][i]==1) answer.push_back({i,j,1});
        }
    }
    return answer;
}