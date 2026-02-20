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
#define endl '\n'

int arr[13][13];
int way[8][2]={{-1,0},{0,1},{1,0},{0,-1},{-1,1},{1,1},{1,-1},{-1,-1}};
int chkX[13];
int ans,N;

void solve(int r){
    if(r==N){
        ans++;
        
        // for(int i=0;i<N;i++){
        //     for(int j=0;j<N;j++) cout<<arr[i][j]<<" ";
        //     cout<<endl;
        // }cout<<endl;
        
        return;
    }
    
    for(int c=0;c<N;c++){
        int y=r, x=c;
        if(arr[y][x]!=0||chkX[x]==1) continue;
        
        int flag=1;
        
        for(int i=0;i<N;i++){            
            if(y-i>=0&&x-i>=0&&arr[y-i][x-i]==1) {flag=0;break;}
            if(y+i<N&&x-i>=0&&arr[y+i][x-i]==1) {flag=0;break;}
            if(y-i>=0&&x-i>=0&&arr[y-i][x-i]==1) {flag=0;break;}
            if(y-i>=0&&x+i<N&&arr[y-i][x+i]==1) {
                flag=0;break;
            }
        }
        
        if(flag==0) continue;
        
        chkX[x]=1;
        arr[y][x]=1;
        solve(r+1);
        
        
        //체크 해제
        chkX[x]=0;
        arr[y][x]=0;
    }
    
}

int solution(int n) {
    N=n;
    solve(0);
    
    
    int answer = ans;
    return answer;
}