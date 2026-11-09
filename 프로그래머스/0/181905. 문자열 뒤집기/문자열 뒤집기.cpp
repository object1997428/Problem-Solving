#include <string>
#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

string solution(string my_string, int s, int e) {
    string answer = my_string.substr(0,s);
    // cout<<"answer: "<<answer<<endl;
    string tmp=my_string.substr(s,(e-s+1));
    // cout<<"tmp: "<<tmp<<endl;
    reverse(tmp.begin(),tmp.end());
    // cout<<"tmp: "<<tmp<<endl;
    
    string b=my_string.substr(e+1);
    // cout<<"b: "<<b<<endl;
    answer+=tmp+b;
    
    
    
    return answer;
}