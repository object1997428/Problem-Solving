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

int arr[102][102][2];
int N;

bool possible_create(int sy,int sx,int t){
    if(sy<0||sx<0||sy>N||sx>N) return true;
    
    if(t==0){//기둥
        if(sy==0) return true;
        else if((sx-1>=0&&arr[sy][sx-1][1])||arr[sy][sx][1]) return true;
        else if(sy-1>=0&&arr[sy-1][sx][0]) return true;
    }
    else{
        if(sy==1&&sx==2){
            cout<<arr[sy-1][sx][0]<<" "<<arr[sy-1][sx+1][0]<<" "<<arr[sy][sx-1][1]<<" "<<arr[sy][sx+1][1]<<endl;
        }
        if((sy-1>=0&&arr[sy-1][sx][0])||(sy-1>=0&&arr[sy-1][sx+1][0])) return true;
        else if((sx-1>=0&&arr[sy][sx-1][1])&&(sx+1<=N&&arr[sy][sx+1][1])) return true;
    }
    return false;
}

bool possible_erase(int sy,int sx,int t){
    if(sy<0||sx<0||sy>N||sx>N) return true;
    if(arr[sy][sx][t]==0) return true;
    
    if(t==0){//기둥
        if(sy==0) return true;
        else if((sx-1>=0&&arr[sy][sx-1][1])||arr[sy][sx][1]) return true;
        else if(sy-1>=0&&arr[sy-1][sx][0]) return true;
    }
    else{
        if(sy==1&&sx==2){
            cout<<arr[sy-1][sx][0]<<" "<<arr[sy-1][sx+1][0]<<" "<<arr[sy][sx-1][1]<<" "<<arr[sy][sx+1][1]<<endl;
        }
        if((sy-1>=0&&arr[sy-1][sx][0])||(sy-1>=0&&arr[sy-1][sx+1][0])) return true;
        else if((sx-1>=0&&arr[sy][sx-1][1])&&(sx+1<=N&&arr[sy][sx+1][1])) return true;
    }
    return false;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    N=n;
    for(auto inp:build_frame){
        int sy=inp[1], sx=inp[0], t=inp[2], o=inp[3];
        cout<<"sy: "<<sy<<" sx: "<<sx<<" t: "<<t<<" o: "<<o<<endl;
        if(o==1){
            if(possible_create(sy,sx,t)){
                arr[sy][sx][t]=o;
                cout<<"possible- sy: "<<sy<<" sx: "<<sx<<" t: "<<t<<endl;
            } 
        }
        else{
            arr[sy][sx][t]=0;
            if(t==0){
                if(possible_erase(sy+1,sx,0)
               &&possible_erase(sy+1,sx-1,1)&&possible_erase(sy+1,sx,1)
              &&possible_erase(sy,sx-1,1)&&possible_erase(sy,sx,1)
              &&possible_erase(sy-1,sx,0)){
                arr[sy][sx][t]=o;
                cout<<"possible- sy: "<<sy<<" sx: "<<sx<<" t: "<<t<<endl;
                }
                else arr[sy][sx][t]=1;
            }
            else{//보
                if(possible_erase(sy,sx,0)&&possible_erase(sy,sx+1,0)
                   &&possible_erase(sy,sx-1,1)&&possible_erase(sy,sx+1,1)
                    &&possible_erase(sy-1,sx,1)&&possible_erase(sy-1,sx+1,1)){
                        arr[sy][sx][t]=0;
                        cout<<"possible- sy: "<<sy<<" sx: "<<sx<<" t: "<<t<<endl;
                    }
                else arr[sy][sx][t]=1;
            }
        }
        
    }
    
    vector<vector<int>> answer;
    for(int j=0;j<=N;j++)for(int i=0;i<=N;i++){
        if(arr[i][j][0]){
            vector<int> tmp={j,i,0};
            answer.push_back(tmp);
        } 
        if(arr[i][j][1]){
            vector<int> tmp={j,i,1};
            answer.push_back(tmp);
        } 
    }
    
    
    
    return answer;
}