#include <iostream>
#include <string>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <cmath>
#include <climits>
using namespace std;

int solution(string s)
{
    int ans=1;
    int N=s.size();
    
    //홀수 버전
    for(int i=1;i<N-1;i++){
        int len=1;
        for(int j=1;j<N;j++){
            int l=i-j;
            int r=i+j;
            if(l>=0&&r>=0&&l<N&&r<N){
                if(s[l]!=s[r]) break;
                len=max(len,2*j+1);
            }
            else break;
        }
        ans=max(ans,len);
    }
    
    //짝수버전
    for(int i=0;i<N;i++){
        //i, i+1이 중간
        if(s[i]!=s[i+1]) continue;
        
        int len=2;
        for(int j=1;j<N;j++){
            int l=i-j;
            int r=i+1+j;
            if(l>=0&&r>=0&&l<N&&r<N){
                if(s[l]!=s[r]) break;
                len=max(len,2*j+2);
            }
            else break;
        }
        ans=max(ans,len);
    }
    
    return ans;
}