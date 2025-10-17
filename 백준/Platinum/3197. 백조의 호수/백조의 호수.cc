#include <string>
#include <vector>
#include <iostream>
#include <climits>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <queue>
#include <string.h>
#pragma warning(disable:4996)
#define endl '\n'
using namespace std;
typedef pair<int,int> pii;
typedef long long int ll;

int sy,sx,ey,ex;
char arr[1501][1501];
char narr[1501][1501];
int chk[1501][1501];
queue<pii> q, nq,temp;
int N,M;

pii parent[1501][1501];


int way[4][2]={{-1,0},{0,1},{1,0},{0,-1}};

pii find(int uy,int ux) {
    if(parent[uy][ux].first==uy&&parent[uy][ux].second==ux) return {uy,ux};

    return parent[uy][ux]=find(parent[uy][ux].first,parent[uy][ux].second);
}

void merge(int uy,int ux, int vy,int vx) {
    pii u=find(uy,ux);
    pii v=find(vy,vx);
    if(u==v) return;

    parent[v.first][v.second]=u;
}


void melting() {

    //q에는 '.'만 들어가있음
    while(!q.empty()) {
        int y=q.front().first,x=q.front().second;
        q.pop();

        arr[y][x]='.';

        for(int w=0;w<4;w++) {
            int ny=y+way[w][0], nx=x+way[w][1];
            //지금은 안녹았고, 다음턴에선 녹을 y,x
            if(ny>=0&&nx>=0&&ny<N&&nx<M&&arr[ny][nx]=='X'&&narr[ny][nx]!='.') {
                nq.push({ny,nx});
                narr[ny][nx]='.';

                //다음턴에 merge지만 1턴 미리.
                merge(y,x,ny,nx);
            }
        }
    }

    while(!nq.empty()) {
        q.push(nq.front());

        int y=nq.front().first, x=nq.front().second;
        //이번에 녹은 것들의 주변에 녹은것 있으면 merge시켜주기
        for(int w=0;w<4;w++) {
            int ny=y+way[w][0], nx=x+way[w][1];
            //y,x도 다음턴에 녹을것들, ny,nx도 다음 턴에 녹아있을 것들(새로든, 기존이든)
            if(ny>=0&&nx>=0&&ny<N&&nx<M&&narr[ny][nx]=='.') {
                //다음턴에 merge지만 1턴 미리.
                merge(y,x,ny,nx);
            }
        }


        nq.pop();
    }
}


void init() {
    cin>>N>>M;

    sy=sx=ey=ex=-1;
    for(int i=0;i<N;i++)for(int j=0;j<M;j++) parent[i][j]={i,j};

    for(int i=0;i<N;i++)for(int j=0;j<M;j++) {
        cin>>arr[i][j];
        if(arr[i][j]=='L') {
            if(sy==-1){sy=i,sx=j;}
            else {ey=i, ex=j;}
            arr[i][j]='.';
        }

        if(arr[i][j]=='.') {
            narr[i][j]='.';
            q.push({i,j});
        }
    }

    for(int i=0;i<N;i++)for(int j=0;j<M;j++) {
        if(arr[i][j]=='.') {
            //'.'들끼리 merge시키기
            int y=i,x=j;

            for(int w=1;w<=2;w++) {
                int ny=y+way[w][0], nx=x+way[w][1];
                //y,x는 녹은상태, ny,nx도 녹았다면 merge
                if(ny>=0&&nx>=0&&ny<N&&nx<M&&arr[ny][nx]=='.') {
                    merge(y,x,ny,nx);
                }
            }
        }

    }

}

void printArr() {
    // for(int i=0;i<N;i++) {
    //     for(int j=0;j<M;j++) {
    //         cout<<narr[i][j]<<" ";
    //     }cout<<endl;
    // }

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cout<<parent[i][j].first*10+parent[i][j].second<<" ";
        }cout<<endl;
    }
}

void solve() {
    // if(find(sy,sx)==find(ey,ex)) {
    //     cout<<0<<endl;
    //     return;
    // }

    for(int i=0;;i++) {
        // cout<<"i: "<<i<<"------"<<endl;
        // printArr();
        if(find(sy,sx)==find(ey,ex)) {
            cout<<i<<endl;
            return;
        }

        melting();
    }
}

int main(){
    //freopen("input.txt","r",stdin);

    init();
    solve();

    //fclose(stdin);
    return 0;
}