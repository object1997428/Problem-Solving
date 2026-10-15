#include <string>
#include <vector>
#include <iostream>
using namespace std;
int chk[101];

int solution(int n) {
    
    for(int i=2;i<=n;i++){
        //합성수면 continue;
        if(chk[i]==1) continue;
        
        //약수
        chk[i]=2;
        // cout<<"약수 i: "<<i<<endl;
        
        //약수의 배수는 합성수
        for(int j=i*2;j<=n;j+=i){
            chk[j]=1;
        }
    }
    
    int cnt=0;
    for(int i=4;i<=n;i++){
        if(chk[i]!=2){
            // cout<<"i: "<<i<<endl;
            cnt++;
        }
    }
    
    
    int answer = cnt;
    return answer;
}