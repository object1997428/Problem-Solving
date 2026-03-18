#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <climits>
using namespace std;
typedef long long ll;


string solution(int n) {
        
    string answer = "";
    
    while(n>0){
        int x=n%3;
        n/=3;
        if(x==0) n--;
        answer="412"[x]+answer;
    }
    
    return answer;
}