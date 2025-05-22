#include <string>
#include <vector>
#include <string.h>
#include <iostream>
#include <climits>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef long long ll;

int arr[11]; //arr[3]=1 이면, 조합이 3개일때 pick
int maxSize;
string picked;
unordered_map<string,int> m1;
vector<string> v;
string maxStr[11];

void pick(string str, int cnt, int start){
    
    // cout<<"picked.size():  "<<picked.size()<<" arr[picked.size()]: "<<arr[picked.size()]<<endl;
    if(arr[picked.size()]==1){
        if(++m1[picked]==2){
            v.push_back(picked);
        }
        // return;
    }
    if(picked.size()==maxSize) return;
    
    for(int i=start;i<str.size();i++){
        picked.push_back(str[i]);
        pick(str,cnt+1,i+1);
        picked.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    for(auto c:course){
        arr[c]=1;
        // cout<<"c: "<<c<<" arr[c]: "<<arr[c]<<endl;
        maxSize=max(maxSize,c);
        // cout<<"maxSize: "<<maxSize<<endl;
    }
    
    
    for(auto str: orders){
        sort(str.begin(),str.end());
        pick(str,0,0);
    }
    
    
    sort(v.begin(),v.end());
    vector<string> ans;
    vector<pis> vv;
    
    for(int i=0;i<v.size();i++){
        string str=v[i];
        int cnt=m1[str];
        vv.push_back({cnt,str});
    }
    sort(vv.begin(),vv.end(),greater<>());
    for(int i=0;i<vv.size();i++){
        string str=vv[i].second;
        int cnt=vv[i].first;
        int sz=str.size();
        // cout<<"str: "<<str<<" cnt: "<<cnt<<" sz: "<<sz<<endl;
        if(maxStr[sz]==""||m1[maxStr[sz]]==cnt){
            maxStr[sz]=str;
            ans.push_back(str);
        }
    }
    
    
    sort(ans.begin(),ans.end());
    return ans;
}