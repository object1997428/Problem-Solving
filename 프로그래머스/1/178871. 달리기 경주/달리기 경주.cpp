#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <climits>
#include <cmath>
#include <cassert>
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string,int> nametoo;
string otoname[50001];
int N;

vector<string> solution(vector<string> players, vector<string> callings) {
    //init
    N=players.size();
    for(int i=0;i<players.size();i++){
        string name=players[i];
        nametoo[name]=i+1;
        otoname[i+1]=name;
    }
    
    //solve
    for(auto name1:callings){
        int o1=nametoo[name1];
        string name2=otoname[o1-1];
        
        nametoo[name1]=o1-1;
        nametoo[name2]=o1;
        otoname[o1-1]=name1;
        otoname[o1]=name2;
    }
    
    
    vector<string> answer;
    for(int i=1;i<=N;i++){
        string name=otoname[i];
        answer.push_back(name);
    }
    
    return answer;
}