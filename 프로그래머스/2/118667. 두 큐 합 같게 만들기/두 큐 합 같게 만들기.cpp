#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <climits>
#include <cassert>
#include <cmath>
#include <iostream>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

vector<ll> v;
int N,M;
ll sum=0;
ll sum1=0, sum2=0;
queue<ll> queue1,queue2;
int isValid(){
    int s=0,e=0;
    ll q=sum/2;
    ll now=v[s];
    // cout<<"q: "<<q<<endl;
    while(s<N+M){
        //i부터 시작해서 sum 할 수 있는지 찾기
        if(now<q){
            e=(e+1>=N+M)?e+1-(N+M):e+1;
            now+=v[e];
            // cout<<"s: "<<s<<" e; "<<e<<" now: "<<now<<endl;
        }else if(now>q){
            now-=v[s];
            s++;
            // cout<<"s: "<<s<<" e; "<<e<<" now: "<<now<<endl;
        }
        else if(now==q){
            // cout<<"find! s: "<<s<<" e; "<<e<<" now: "<<now<<endl;
            return s+(e-(N-1));
            // return -1;
        }
    }
    return -1;
}

int solve(){
    int ret=0;
    
    int count=10;
    while(sum1!=sum2){
        while(sum1>sum2){
            queue2.push(queue1.front()); sum2+=queue1.front();
            sum1-=queue1.front(); queue1.pop();
            ret++;
        }
        
        while(sum2>sum1){
            queue1.push(queue2.front()); sum1+=queue2.front();
            sum2-=queue2.front(); queue2.pop();
            ret++;
        }
    }
    return ret;
}

int solution(vector<int> q1, vector<int> q2) {
    //가능하긴 한지 체크
    N=q1.size(),M=q2.size();
    
    for(int i=0;i<q1.size();i++){
        v.push_back(q1[i]);
        sum+=q1[i];
        sum1+=q1[i];
        queue1.push(q1[i]);
    }
    for(int i=0;i<q2.size();i++){
        v.push_back(q2[i]);
        sum+=q2[i];
        sum2+=q2[i];
        queue2.push(q2[i]);
    }
    int ret=isValid();
    if(ret==-1) return -1;
    // cout<<"ret: "<<ret<<endl;
    
    
    
    return solve();
}