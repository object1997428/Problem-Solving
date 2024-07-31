#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
#include <climits>
#include <cmath>
#include <cassert>
#include <iostream>
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> pip;

vector<int> cards;
int N, cIdx, coin;
int maxR;
int chked[1001]; //[카드숫자]=카드 위치+1
int cnt=0;
priority_queue<pip,vector<pip>,greater<>> q;

int saveCoin;
void solve(int r){
    maxR=max(maxR,r);
    if(maxR>N/3) return;
    cnt++;
    //2. 카드 2장 뽑기(coin은 쓸때 지불할거임)
    for(int i=0;i<2;i++){
        if(cIdx==N) return;
        chked[cards[cIdx]]=cIdx+1;
        int op=N+1-(cards[cIdx]);
        if(chked[op]>0){
            if(chked[op]<=N/3) q.push({1,{cards[cIdx], op}});
            else q.push({2,{cards[cIdx], op}});
        }
        cIdx++;
    }
    
    //3. n+1되는 카드 2장 지불하기
    while(!q.empty()){
        int w=q.top().first;
        int a=q.top().second.first;
        int b=q.top().second.second;
        q.pop();
        int aIdx=chked[a], bIdx=chked[b];
        if(coin<w) continue;
        
        coin-=w;
        chked[a]=0, chked[b]=0;
        
        cout<<"r: "<<r<<" a: "<<a<<" b: "<<b<<endl;
        solve(r+1);
        
        coin+=w;
        chked[a]=aIdx, chked[b]=bIdx;
    }
    
    cIdx-=2;
}

int solution(int _coin, vector<int> _cards) {
    //init
    cards=_cards;
    N=cards.size();
    memset(chked,0,sizeof(chked));
    for(int i=0;i<N/3;i++){
        chked[cards[i]]=i+1;
        int op=N+1-(cards[i]);
        if(chked[op]>0) q.push({0,{cards[i], op}});
    } 
    cIdx=N/3; coin=_coin;
    
    solve(1);

    int answer = maxR;
    return answer;
}