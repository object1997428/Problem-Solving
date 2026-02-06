#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cassert>
#include <climits>
#include <stack>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define endl '\n'

int N;
stack<int> s1[31];
int solution(vector<vector<int>> board, vector<int> moves) {
    
    N=board.size();
    
    for(int i=0;i<N;i++){
        for(int j=N-1;j>=0;j--){
            if(board[j][i]!=0){
                s1[i].push(board[j][i]);
                // cout<<s1[i].top()<<" ";
            }
        }
    }
    
    
    
    stack<int> box;
    
    int ans=0;
    for(int i=0;i<moves.size();i++){
        int k=moves[i]-1;
        
        if(s1[k].empty()) continue;
        // cout<<"k: "<<k<<" top: "<<s1[k].top()<<endl;
        int x=s1[k].top(); s1[k].pop();
        
        if(!box.empty()&&box.top()==x){
            box.pop();
            ans+=2;
        }
        else box.push(x);
    }
    
    
    int answer = ans;
    return answer;
}