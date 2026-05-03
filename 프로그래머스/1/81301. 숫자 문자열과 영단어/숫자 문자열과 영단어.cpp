#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <climits>
#include <cassert>
#include <cmath>
#include <iostream>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

string arr[10]={"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};



int solution(string s) {
    
    int idx=0;
    string ans="";
    while(idx<s.size()){
        string word3=s.substr(idx,3);
        string word4=s.substr(idx,4);
        string word5=s.substr(idx,5);
        if(word3=="one") ans+='1', idx+=3;
        else if(word3=="two") ans+='2', idx+=3;
        else if(word3=="six") ans+='6', idx+=3;
        else if(word4=="zero") ans+='0', idx+=4;
        else if(word4=="four") ans+='4', idx+=4;
        else if(word4=="five") ans+='5', idx+=4;
        else if(word4=="nine") ans+='9', idx+=4;
        else if(word5=="three") ans+='3', idx+=5;
        else if(word5=="seven") ans+='7', idx+=5;
        else if(word5=="eight") ans+='8', idx+=5;
        else {ans+=s.substr(idx,1); idx++;}
    }
    
    
    
    int answer = stoi(ans);
    return answer;
}