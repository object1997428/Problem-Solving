#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string myString, string pat) {
    
    int idx=0;
    string str=myString;
    string answer="";
    while(1){
        int ret=str.find(pat);
        if(ret>=str.size()) break;
        else {
            answer+=str.substr(0,ret+pat.size());
            str=str.substr(ret+pat.size());
        }
    }

    
    return answer;
}