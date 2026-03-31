#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cassert>
#include <cmath>
#include <stack>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int line[102];
int out[102];
vector<int> g[102];
int N,V;
stack<pii> s1;
int gg[1002][1002];



int solution(int n, vector<vector<int>> results) {
    N=n; V=results.size();
    
    for(int i=0;i<V;i++){
        int w=results[i][0];
        int l=results[i][1];
        g[l].push_back(w);
        line[w]++;
        out[l]++;
        gg[l][w]=1;
    }
  
    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(gg[i][k]==1&&gg[k][j]==1&&gg[i][j]==0){
                    gg[i][j]=1;
                    line[j]++; out[i]++;
                }
            }
        }
    }
   
    int cnt=0;
    for(int i=1;i<=N;i++) if(line[i]+out[i]==N-1){
        cnt++;
    }
    
    
    
    int answer = cnt;
    return answer;
}
