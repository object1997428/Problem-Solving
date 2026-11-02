#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int i, int j, int k) {
    
    int answer = 0;
    
    char p='0'+k;
    
    for(int a=i;a<=j;a++){
        string s=to_string(a);
        for(char c:s){
            if(c==p){
                answer++;
            }
        }
    }
    
    return answer;
}