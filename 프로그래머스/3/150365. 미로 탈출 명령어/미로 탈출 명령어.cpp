#include <string>
#include <vector>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <cassert>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define endl '\n'

int way[4][2]={{1,0},{0,-1},{0,1},{-1,0}};
char c[4]={'d','l','r','u'};
int N,M,sy,sx,ey,ex,K;
string ans;
int flag=0;
void solve(int y,int x,string cur){
    // cout<<"y: "<<y<<" x; "<<x<<" cur: "<<cur<<endl;
    if(flag) return;
    int remain=abs(ey-y)+abs(ex-x);
    if(K<remain+cur.size()) return;
    if(y==ey&&x==ex){
        if(K==cur.size()){
            // cout<<"ans: "<<ans<<" < cur: "<<cur<<endl;
            ans=cur; flag=1;
            return;
        }
    }
    if(cur.size()>=K) return;
    
    
    for(int i=0;i<4;i++){
        int ny=y+way[i][0];
        int nx=x+way[i][1];
        string next=cur+c[i];
        if(ny>=0&&nx>=0&&ny<N&&nx<M){
            solve(ny,nx,next);
            if(flag) return;
        }
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    // vector<char> v;
    string v;
    N=n,M=m; sy=x-1,sx=y-1,ey=r-1,ex=c-1, K=k;
    
    //solve
    //1. 최단경로
    if(x<r) for(int i=0;i<r-x;i++) v.push_back('d');
    else if(x>r) for(int i=0;i<x-r;i++) v.push_back('u');
    if(y<c) for(int i=0;i<c-y;i++) v.push_back('r');
    else if(y>c) for(int i=0;i<y-c;i++) v.push_back('l');
    
    if(k<v.size()) return "impossible";
    if(k%2!=v.size()%2) return "impossible";
    
    sort(v.begin(),v.end());
    if(k==v.size()) return v;
    
    //solve
    ans="";
    for(int i=0;i<k;i++) ans.push_back('z');
    string maxans=ans;
    solve(sy,sx,"");
    
    string answer = ans;
    if(ans==maxans) ans= "impossible";
    return answer;
}