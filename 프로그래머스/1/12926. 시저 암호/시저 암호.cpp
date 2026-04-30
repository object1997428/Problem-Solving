#include <string>
#include <vector>
#include <string.h>
#include <iostream>
#include <climits>
#include <cassert>
#include <cmath>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;


string solution(string s, int n) {
    
    string answer = "";
    for(int i=0;i<s.size();i++){
        char c=s[i];
        if(c==' ') {answer+=' '; continue;}
        
        for(int j=0;j<n;j++){
            c++;
            if(s[i]>='A'&&s[i]<='Z'&&c>'Z') c='A';
            else if(s[i]>='a'&&s[i]<='z'&&c>'z') c='a';
        }
        answer+=c;
    }
    

    return answer;
}