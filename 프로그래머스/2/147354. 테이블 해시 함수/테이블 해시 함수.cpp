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

int N,M,col;
bool comp(vector<int> v1,vector<int> v2){
    if(v1[col]==v2[col]) return v1[0]>v2[0];
    return v1[col]<v2[col];
}

int solution(vector<vector<int>> data, int _col, int row_begin, int row_end) {
    N=data.size(), M=data[0].size();
    col=_col-1;
    
    sort(data.begin(),data.end(),comp);
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<M;j++) cout<<data[i][j]<<" ";
    //     cout<<endl;
    // }
    
    int ans=-1;
    for(int i=row_begin-1;i<=row_end-1;i++){
        int S_i=0;
        for(int j=0;j<M;j++){
            S_i+=data[i][j]%(i+1);
        }
        if(ans==-1) ans=S_i;
        else ans^=S_i;
    }
    
    
    int answer = ans;
    return answer;
}