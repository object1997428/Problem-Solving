#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cmath>
#include <cassert>
#include <stack>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

stack<int> s1;
vector<int> tmp;

bool isValid(){
    if(s1.size()<3) return false;
    
    for(int i=0;i<3;i++){
        tmp.push_back(s1.top()); s1.pop();
    }
    
    // cout<<"tmp[0]: "<<tmp[0]<<" tmp[1]: "<<tmp[1]<<" tmp[2]: "<<tmp[2]<<endl;
    
    if(tmp[0]==3&&tmp[1]==2&&tmp[2]==1){
        tmp.clear();
        return true;
    }
    //else
    while(!tmp.empty()){ s1.push(tmp.back()); tmp.pop_back();}
    return false;
    
}

int solution(vector<int> ingredient) {
    int N=ingredient.size();
    
    int count=0;
    for(int i=0;i<N;i++){
        int cur=ingredient[i];
        if(cur==1){
            if(isValid()) count++;
            else s1.push(cur);
        }
        else s1.push(cur);
    }
    
    
    int answer = count;
    return answer;
}