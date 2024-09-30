#include <string>
#include <vector>
#include <iostream>
#include <climits>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <queue>
#pragma warning(disable:4996)
#define endl '\n'
using namespace std;
typedef pair<int,int> pii;
typedef long long int ll;


int N,M;
int sy,sx;
queue<pii> q;
char arr[601][601];
int chked[601][601];
int way[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int ans=0;

void init(){
    cin>>N>>M;
    for(int i=0;i<N;i++)for(int j=0;j<M;j++){
        cin>>arr[i][j];
        if(arr[i][j]=='I') sy=i,sx=j;
    } 

}

void solve(){
    q.push(make_pair(sy, sx));
    chked[sy][sx]=1;
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        
        for(int w=0;w<4;w++){
            int ny=y+way[w][0];
            int nx=x+way[w][1];
            if(ny>=0&&nx>=0&&ny<N&&nx<M&&arr[ny][nx]!='X'&&chked[ny][nx]==0){
                chked[ny][nx]=1;
                q.push(make_pair(ny, nx));
                if(arr[ny][nx]=='P') ans++;
            }
        }
    }
    if(ans==0) cout<<"TT"<<endl;
    else cout<<ans<<endl;
}

int main(){
    //freopen("input.txt","r",stdin);
    
    init();
    solve();
    
    //fclose(stdin);
    return 0;
}