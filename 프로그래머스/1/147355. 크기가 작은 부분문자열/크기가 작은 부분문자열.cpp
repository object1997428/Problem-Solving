#include <string>
#include <vector>
#include <string.h>
#include <iostream>
#include <climits>
#include <algorithm>
#include <cmath>
#include <cassert>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int solution(string t, string p) {
    int N=t.size(), M=p.size();
    ll numP=stol(p);  
    int answer = 0;
    string x="";
    for(int i=0;i<N-M+1;i++){
        x=t.substr(i,M);
        // cout<<"x: "<<x<<endl;
        
        ll numX=stol(x);
        if(numX<=numP) answer++;
    }
    
    
    return answer;
}