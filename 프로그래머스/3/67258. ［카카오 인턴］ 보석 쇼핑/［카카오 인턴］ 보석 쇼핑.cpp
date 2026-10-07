#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <cassert>
#include <cmath>
#include <climits>
#include <unordered_map>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

unordered_map<string,int> type2num;
unordered_map<string,int> tsum;

int TN,N; //총 종류 수
int TMAX;
int THASH; //현재 종류 현황

vector<int> solution(vector<string> gems) {
    //총 type수 파악
    TN=1;
    N=gems.size();
    for(int i=0;i<gems.size();i++){
        string s=gems[i];
        tsum[s]++;
    }
    TMAX=tsum.size();
    // cout<<"TMAX: "<<TMAX<<endl;
    
    //처음 s,e 찾기
    int s=0,e=-1;
    tsum.clear();
    int ans=INT_MAX;
    // cout<<"tsum.size(): "<<tsum.size()<<endl;
    
    vector<int> answer;
    while(e<N-1){
        e++;
        for(;e<N;e++){
            string t=gems[e];
            tsum[t]++;

            if(tsum.size()==TMAX){
                // cout<<"e: "<<e<<endl;
                break;
            }
        }
        //e에 맞춰서 s 당기기
        for(;s<N;s++){
            //[s+1,e]를 테스트하기위해 [s,s]를 빼보기.
            string t=gems[s];
            tsum[t]--;
            if(tsum[t]==0){
                tsum.erase(t);
            }
            
            //[s+1,e]인데 1111을 만족하지 못함
            //그럼 [s,e]에서 멈추기
            // cout<<"s: "<<s<<" tsum.size(): "<<tsum.size()<<endl;
            if(tsum.size()!=TMAX){
                
                // cout<<"s: "<<s<<endl;
                tsum[t]++;
                break;
            }
            
            //[s+1,e]가 1111을 만족함 -> s를 뺀 tsum[]그대로 넘어감.
        }
        // cout<<"e-s: "<<e-s<<" s: "<<s<<" e: "<<e<<endl;
        if(e-s<ans){
            ans=e-s;
            while(!answer.empty()) answer.pop_back();
            answer.push_back(s+1);
            answer.push_back(e+1);
        }
    }

    
    
    
    
    return answer;
}