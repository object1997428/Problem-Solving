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

typedef struct node{
    int needA,needB,plusA,plusB,cost;
}node;
vector<node> v;
int comp(node v1,node v2){
    int p1=(v1.plusA+v1.plusB)/v1.cost;
    int p2=(v2.plusA+v2.plusB)/v2.cost;
    if(v1.cost==v2.cost) return false;
    return v1.cost>v2.cost;
}


int maxA,maxB,minA,minB;
int M;
int ans;
int dp[1001][1001];

int solve(int A,int B,int sum){
    if(A>=maxA&&B>=maxB){
        ans=min(ans,sum);
        return 0;
    }
    // if(sum>=ans) return INT_MAX;
    A=min(A,maxA);
    B=min(B,maxB);
    int& ret=dp[A][B];
    if(ret!=-1) return ret;
    
    ret=INT_MAX;
    for(int i=0;i<v.size();i++){
        //풀 수 있으면
        if(A>=v[i].needA&&B>=v[i].needB){
            //필요하면
            if((maxA-A>0&&v[i].plusA>0)||(maxB-B>0&&v[i].plusB>0)){
                ret=min(ret,solve(A+v[i].plusA,B+v[i].plusB, sum+v[i].cost)+v[i].cost);
                // cout<<"A+v[i].plusA: "<<A+v[i].plusA<<" B+v[i].plusB: "<<B+v[i].plusB<<" ret: "<<ret<<endl;
            }
        }
    }
    if(maxA-A>0){
        ret=min(ret,solve(A+1,B,sum+1)+1);
    } 
    if(maxB-B>0){
        ret=min(ret,solve(A,B+1,sum+1)+1);
    }
    
    return ret;
}


int solution(int alp, int cop, vector<vector<int>> problems) {
    
    M=problems.size();
    ans=INT_MAX;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<M;i++){
        maxA=max(maxA,problems[i][0]);
        maxB=max(maxB,problems[i][1]);
        minA=min(minA,problems[i][0]);
        minB=min(minB,problems[i][1]);
        int plusA=problems[i][2];
        int plusB=problems[i][3];
        int cost=problems[i][4];
        
        if(plusA==0&&plusB==0) continue; //아무것도 plus못하면 넣지X
        v.push_back({problems[i][0], problems[i][1], plusA, plusB, cost});
    }
    // sort(v.begin(),v.end(),comp);
    // for(int i=0;i<v.size();i++){
    //     cout<<"plusA: "<<v[i].plusA<<" plusB: "<<v[i].plusB<<endl;
    // }
    
    int ret=solve(alp,cop,0);
    
    
    int answer = ret;
    return answer;
}