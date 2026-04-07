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
typedef pair<int,int> pii;
typedef long long ll;

vector<pii> v1;
int arr[20001];
unordered_map<string,int> m1;

int solution(string message, vector<vector<int>> spoiler_ranges) {
    for(auto se:spoiler_ranges){
        int s=se[0];
        int e=se[1];
        for(int i=s;i<=e;i++){
            arr[i]=1;
        }
    }
    
    
    string word="";
    bool isSpolierWord=0;
    for(int i=0;i<message.size();i++){
        char c=message[i];
        if(c==' '){ //단어 완성
            if(isSpolierWord){
                // cout<<"스포맞음: "<<word<<endl;
                if(m1[word]==0) m1[word]=1;
                //2,3일땐 그대로
            }
            else{
                // cout<<"스포아님: "<<word<<endl;
                if(m1[word]==1) m1[word]=2;
                else if(m1[word]==0) m1[word]=2;
            }
            
            isSpolierWord=0;
            word="";
        }
        else {
            word+=c;
            if(arr[i]) isSpolierWord=1;
        }
    }
    if(word!=""){
        if(isSpolierWord){
            // cout<<"스포맞음: "<<word<<endl;
            if(m1[word]==0) m1[word]=1;
            //2,3일땐 그대로
        }
        else{
            // cout<<"스포아님: "<<word<<endl;
            if(m1[word]==1) m1[word]=2;
            else if(m1[word]==0) m1[word]=2;
        }
    }
    
    
    
    
    int cnt=0;
    for(auto& val:m1){
        if(val.second==1) {
            cnt++;
            // cout<<val.first<<endl;
        }
    }
    
    
    int answer = cnt;
    return answer;
}