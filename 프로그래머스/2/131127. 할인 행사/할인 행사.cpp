#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <climits>
#include <cmath>
#include <cassert>
#include <unordered_map>
#include <iostream>
using namespace std;

int len;
int itoStr[12];
int sum[12]; // [제품명]=개수
unordered_map<string,int> str2i;

vector<string> want;
vector<int> number;
vector<string> discount;

bool isValid(){
    for(int i=1;i<=len;i++){
        if(number[i-1]>sum[i]) return false;
    }
    return true;
}

int solution(vector<string> _want, vector<int> _number, vector<string> _discount) {
    want=_want; number=_number; discount=_discount;
    len=want.size();
    
    for(int i=0;i<len;i++){
        string name=want[i];
        str2i[name]=i+1;
    }
    
    for(int i=0;i<10;i++){
        string name=discount[i];
        int name_i=str2i[name];
        sum[name_i]++;
        
        // cout<<"name: "<<name<<" sum[name_i]: "<<sum[name_i]<<endl;
    }
    //[0~len) 체크
    int ans = 0;
    if(isValid()) ans++;

    // cout<<"ans: "<<ans<<endl;
    
    for(int i=10;i<discount.size();i++){
        int prev=i-10;
        int cur=i;
        int start=prev+1;
        
        string name=discount[prev];
        int name_prev=str2i[name];
        if(name_prev!=0) sum[name_prev]--;
        
        string namec=discount[cur];
        int name_cur=str2i[namec];
        if(name_cur!=0) sum[name_cur]++;
        
        // cout<<"start: "<<start<<endl;
        
        // for(int i=1;i<=len;i++){
        //     cout<<sum[i]<<" ";
        // }
        
        // if(i==11){
        //     cout<<"namec: "<<namec<<endl;
        //     cout<<"name_cur: "<<name_cur<<endl;
        //     cout<<
        // }
        
        if(isValid()){
            // cout<<"start: "<<start<<"에서 시작하는데 가능하다"<<endl;
            
            ans++;
        }
        
    }
    
    return ans;
}