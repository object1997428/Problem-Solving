#include <string>
#include <vector>
#include <string.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include <climits>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int ans;
int N,M;
vector<vector<string>> relation;
vector<int> v;
unordered_map<string,int> m1;

bool validate(){
    
    
    //유일성
    m1.clear();
    for(int i=0;i<N;i++){
        string sum="";
        for(int j=0;j<v.size();j++){
            sum+=relation[i][v[j]];
        }
        if(++m1[sum]>1) return false;
    }
    // cout<<"통과1"<<endl;
    
    //최소성
    for(int k=0;k<v.size();k++){
        //v[k] 빠지면 중복되어야함. 유일하면 안됨
        m1.clear();
        
        int flag=0;
        for(int i=0;i<N;i++){
            string sum="";
            for(int j=0;j<v.size();j++){
                if(k==j) continue;
                sum+=relation[i][v[j]];
            }
            //중복됨
            if(++m1[sum]>1) {flag=1; break;}
        }
        // cout<<"통과2-"<<k<<
        //중복되지않으면 최소성X
        if(flag==0) return false;
    }
    
    return true;
}

void pick(int cnt,int start){
    if(cnt>=1){
        if(validate()){
            // cout<<"통과: ";
            // for(int i=0;i<v.size();i++) cout<<v[i]<<" "; cout<<endl;
            ans++;
            return;
        }
    }
    
    for(int i=start; i<M;i++){
        v.push_back(i);
        pick(cnt+1, i+1);
        v.pop_back();
    }
}

int solution(vector<vector<string>> _relation) {
    relation=_relation;
    N=relation.size(), M=relation[0].size();
    
    pick(0,0);
    
    
    int answer = ans;
    return answer;
}