#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <climits>
#include <cassert>
#include <cmath>
#include <iostream>
using namespace std;
typedef pair<int,int> pii;

vector<int> solution(vector<string> wallpaper) {
    int sy=INT_MAX,sx=INT_MAX,ey=INT_MIN,ex=INT_MIN;
    for(int i=0;i<wallpaper.size();i++){
        for(int j=0;j<wallpaper[0].size();j++){
            if(wallpaper[i][j]=='#'){
                // cout<<"i: "<<i<<" j: "<<j<<endl;
                sy=min(sy,i);
                ey=max(ey,i);
                sx=min(sx,j);
                ex=max(ex,j);
            }
        }
    }
    
    vector<int> answer;
    answer.push_back(sy); answer.push_back(sx);
    answer.push_back(ey+1); answer.push_back(ex+1);
    return answer;
}