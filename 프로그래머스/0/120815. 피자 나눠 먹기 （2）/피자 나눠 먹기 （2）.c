#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef long long ll;

int solution(int n) {
    int k=floor(n/6);
    if(k*6<n) k++;
    for(;;k++){
        ll cnt=k*6;
        if(cnt%n==0) return k;
    }
    
    
    int answer = 0;
    return answer;
}