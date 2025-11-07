#include <string>
#include <vector>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cassert>
#include <cmath>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int cost[3][3]={{1,1,1},{5,1,1},{25,5,1}};
typedef struct node {
    int num;
    int d,i,s;
}node;
bool comp(node a, node b){
    if(a.d==b.d){
        if(a.i==b.i) return a.num<b.num;
        return a.i>b.i;
    }
    return a.d>b.d;
}
vector<node> v;

int solution(vector<int> picks, vector<string> minerals) {
    //5개씩 끊어서 넣기
    int M=minerals.size();
    int count=0;
    for(int k=0;k<M;k+=5){
        int dcnt=0,icnt=0,scnt=0;
        for(int i=0;i<5&&k+i<M;i++){
            string x=minerals[k+i];
            if(x=="diamond") dcnt++;
            else if(x=="iron") icnt++;
            else if(x=="stone") scnt++;
        }
        v.push_back({count++,dcnt,icnt,scnt});
    }

    
    sort(v.begin(),v.end(),comp);
    int N=picks[0]+picks[1]+picks[2];//캘 수 있는 5개 묶음 보따리 갯수
    // for(int i=0;i<v.size();i++){
    //     cout<<"v[i][0]: "<<v[i].d<<" v[i][1]: "<<v[i].i<<" v[i][2]: "<<v[i].s<<endl;
    // }
    
    int sum=0;
    for(int i=0;i<v.size();i++){
        //한 묶음당, 다>철>돌 곡괭이 순으로 부여
        if(v[i].num>=N) continue;
        int y=0;
        if(picks[0]>0) {y=0; --picks[0];}
        else if(picks[1]>0) {y=1; --picks[1];}
        else if(picks[2]>0) {y=2; --picks[2];}
        else break;
        
        sum+=cost[y][0]*v[i].d;
        sum+=cost[y][1]*v[i].i;
        sum+=cost[y][2]*v[i].s;
        
        // cout<<"y: "<<y<<" sum: "<<sum<<endl;
    }
    
    
    int answer = sum;
    return answer;
}