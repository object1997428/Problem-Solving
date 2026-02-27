#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <climits>
#include <cassert>
#include <cmath>
#include <iostream>
#define endl '\n'
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

vector<int> tmp;
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    
    vector<int> answer;
    for(auto command:commands){
        int s=command[0]-1,e=command[1]-1,k=command[2]-1;
        // cout<<"s: "<<s<<" e: "<<e<<" k: "<<k<<endl;
        
        //[s,e] 복사
        for(int i=s;i<=e;i++) tmp.push_back(array[i]);
        
        sort(tmp.begin(),tmp.end());
        int x=tmp[k];
        // cout<<"x: "<<x<<endl;
        answer.push_back(x);
        tmp.clear();
    }
    
    
    return answer;
}