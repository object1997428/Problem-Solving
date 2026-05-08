#include <string>
#include <vector>
#include <string.h>
#include <climits>
#include <cassert>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
typedef pair<int,int> pii;

stack<int> s1;

string solution(string number, int k) {
    //init

    for(char c:number){
        int n=c-'0';
        while(!s1.empty()&&s1.top()<n&&k>0){ //s1.top이 맨뒤
            k--;
            s1.pop();
        }
        s1.push(n);
    }
    
    while(k>0) {s1.pop(); k--;}
    
    string answer="";
    while(!s1.empty()){
        char c=s1.top()+'0'; s1.pop();
        answer+=c;
    }
    reverse(answer.begin(),answer.end());
    
    
    return answer;
}