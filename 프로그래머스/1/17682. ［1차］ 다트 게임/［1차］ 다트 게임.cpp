#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cassert>
#include <cmath>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int ans[3];

int solution(string arr) {
    
    int cnt=0,cur=0;
    while(cnt<3){
        //숫자 구하기
        int num=0;
        // cout<<"arr[cur]: "<<arr[cur]<<endl;
        num=arr[cur++]-'0';
        
        if(arr[cur]>='0'&&arr[cur]<='9'){
            // cout<<"arr[cur]: "<<arr[cur]<<endl;
            num=num*10+(arr[cur++]-'0');
        }
        
        // cout<<"num: "<<num<<endl;
        
        //알파벳
        if(arr[cur]=='D') num=pow(num,2);
        else if(arr[cur]=='T') num=pow(num,3);
        cur++;
        // cout<<"num: "<<num<<endl;
        
        //옵션
        if(arr[cur]=='*'){
            num*=2;
            if(cnt>0) ans[cnt-1]*=2;
            cur++;
        }
        else if(arr[cur]=='#'){
            num*=-1;
            cur++;
        } 
        
        
        // cout<<"num: "<<num<<endl;
        
        ans[cnt++]=num;
    }
    
    // cout<<"ans[0]: "<<ans[0]<<" ans[1]: "<<ans[1]<<" ans[2]: "<<ans[2]<<endl;
    
    int answer = ans[0]+ans[1]+ans[2];
    return answer;
}