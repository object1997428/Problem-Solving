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
typedef long long int ll;

int arr[201][10];
int N;
int putBox(int n,int m,int num){
    int k=1,ycnt=0;
    N=(n+m-1)/m;
    int y=N-1;
    while(k<=n){
        if(ycnt%2==0){// ->
            for(int x=0;x<m;x++){
                arr[y][x]=k++;
                 if(k==n+1) return -1;
                
            }
        }
        else{ //<-
            for(int x=m-1;x>=0;x--){
                arr[y][x]=k++;
                if(k==n+1) return -1;
            }
        }
        y--; ycnt++;
    }
    return -1;
}

int solution(int n, int w, int num) {
    int answer = 0;
    putBox(n,w,num);
    
    for(int i=0;i<N;i++){
        for(int j=0;j<w;j++) cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    
    int y,x;
    for(int i=0;i<N;i++){
        for(int j=0;j<w;j++){
            if(arr[i][j]==num){
                y=i,x=j;
                break;
            }
        }
    }
    // cout<<"x: "<<x<<" y: "<<y<<endl;
    for(int i=0;i<N;i++){
        if(arr[i][x]!=0) answer++;
        if(arr[i][x]==num) break;
    }
    
    return answer;
}