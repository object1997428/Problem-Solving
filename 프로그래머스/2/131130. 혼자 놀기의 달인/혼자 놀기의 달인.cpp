#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cassert>
#include <cmath>
#define endl '\n'
using namespace std;

vector<int> cards;
int chk[101];
int N;
int ans=0;

vector<int> tmp2;

int simulation2(int start,int cnt1){
    int cur=start;
    int cnt2=1;
    chk[cur]=1;
    tmp2.push_back(cur);
    while(cnt1+cnt2<N){ //>= 로 했음.. 바보야......
        int next=cards[cur]-1;
        // cout<<"cur: "<<cur<<" next: "<<next<<endl;
        if(chk[next]==0){
            chk[next]=1;
            cnt2++;
            cur=next; //여기 빠뜨림
            tmp2.push_back(cur);
        }
        else break;
    }
    for(auto x:tmp2) chk[x]=0;
    return cnt2;
}

int simulation1(int start,int start2){
    memset(chk,0,sizeof(chk));
    int cnt1=1;
    int cur=start;
    chk[cur]=1;
    while(cnt1<N){
        int next=cards[cur]-1;
        // cout<<"cur: "<<cur<<" next: "<<next<<endl;
        if(chk[next]==0){
            chk[next]=1;
            cnt1++;
            cur=next;
        }
        else{
            cur=next;
            break;
        } 
    }
    if(cnt1==N||chk[start2]!=0) return 0;
   int cnt2=1;
    cur=start2;
    chk[cur]=1;
    while(cnt1+cnt2<N){ //>= 로 했음.. 바보야......
        int next=cards[cur]-1;
        // cout<<"cur: "<<cur<<" next: "<<next<<endl;
        if(chk[next]==0){
            chk[next]=1;
            cnt2++;
            cur=next; //여기 빠뜨림
        }
        else break;
    }
    if(cnt1*cnt2==16&&ans!=16){
        for(auto x: cards) cout<<x<<" ";
        cout<<"\nstart: "<<start<<" start2: "<<start2<<endl;
        // cout<<endl;
    }
    return cnt1*cnt2;
}



int solution(vector<int> _cards) {
    cards=_cards;
    // sort(cards.begin(),cards.end());
    

    N=cards.size();
    int chk11=0;
    
    
    // do{
    //     for(int i=0;i<N;i++){
    //         for(int j=0;j<N;j++){
    //             if(i==j) continue;
    //             int ret=simulation1(i,j);
    //             if(ret==0) continue;
    //             ans=max(ret,ans);
    //         }
    //     }
    // }while(next_permutation(cards.begin(),cards.end()));
    for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(i==j) continue;
                int ret=simulation1(i,j);
                if(ret==0) continue;
                ans=max(ret,ans);
            }
        }
    
    
    int answer = ans;
    return answer;
}