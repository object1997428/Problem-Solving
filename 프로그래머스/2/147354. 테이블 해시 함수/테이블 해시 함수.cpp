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
typedef pair<pii,int> pip;
typedef long long ll;

vector<pip> v;
int N,M;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    
    N=data.size(),M=data[0].size();
    for(int i=0;i<N;i++){
        v.push_back({{data[i][col-1],-data[i][0]},i});
    }
    sort(v.begin(),v.end());
    // for(int i=0;i<N;i++){
    //     cout<<v[i].first.first<<" "<<v[i].first.second<<" "<<v[i].second;
    //     cout<<endl;
    // }
    
    int ans=-1;
    for(int i=row_begin-1;i<=row_end-1;i++){
        int sum=0;
        int idx=v[i].second;
        for(int j=0;j<M;j++){
            // cout<<" data[idx][j]: "<<data[idx][j]<<" i+1: "<<i+1<<endl;
            sum+=(data[idx][j]%(i+1));
        }
        // cout<<"sum: "<<sum<<endl;
        if(ans==-1) ans=sum;
        else ans^=sum;
    }
    
    
    int answer = ans;
    return answer;
}