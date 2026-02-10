#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <climits>
#include <cassert>
#include <cmath>
#include <iostream>
using namespace std;
typedef pair<double,int> pii;
typedef long long ll;

int sum[200002];
double fail[200002];

vector<pii> v1;

bool comp(pii& v1, pii& v2){
    if(v1.first==v2.first) return v1.second<v2.second;
    return v1.first>v2.first;
}

vector<int> solution(int N, vector<int> stages) {
    
    for(int i=0;i<stages.size();i++){
        int k=stages[i];
        sum[k]++;
    }
    
    for(int i=1;i<=N+1;i++) sum[i]=sum[i-1]+sum[i];

    cout<<"sum[6]: "<<sum[6]<<endl;
    
    for(int i=1;i<=N;i++){
        if(sum[N+1]-sum[i-1]==0) fail[i]=0;
        else fail[i]=(double)(sum[i]-sum[i-1])/(sum[N+1]-sum[i-1]);
        
        // cout<<"i: "<<i<<" stages[i]: "<<sum[i]-sum[i-1]<<" sum[N+1]-sum[i]: "<<sum[N+1]-sum[i-1]<<endl;
        
        v1.push_back({fail[i],i});
    }
    
    sort(v1.begin(),v1.end(),comp);
    
    vector<int> answer;
    for(int i=0;i<v1.size();i++){
        // cout<<"v1[i].second: "<<v1[i].second<<" v1[i].first: "<<v1[i].first<<endl;
        answer.push_back(v1[i].second);
    }
    
    
    
    return answer;
}