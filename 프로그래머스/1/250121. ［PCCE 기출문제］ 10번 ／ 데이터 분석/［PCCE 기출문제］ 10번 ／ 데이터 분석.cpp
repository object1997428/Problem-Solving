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

vector<pii> v;

int setK(string ext){
    if(ext=="code") return 0;
    else if(ext=="date") return 1;
    else if(ext=="maximum") return 2;
    return 3; //remain
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    int N=data.size(), M=data[0].size();
    int P=setK(ext);
    int Q=setK(sort_by);
    

    for(int i=0;i<N;i++){
        v.push_back({data[i][Q],i});
    }
    sort(v.begin(),v.end());
    
    vector<vector<int>> answer;
    for(int i=0;i<N;i++){
        int idx=v[i].second;
        int x=data[idx][P];
        if(x<val_ext){
            answer.push_back(data[idx]);
        }
    }
    
    return answer;
}