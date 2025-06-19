#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <climits>
#include <cassert>
#include <cmath>
#include <string.h>
#include <stack>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

stack<char> s1;

int solution(string s)
{
    
    for(int i=0;i<s.size();i++){
        if(!s1.empty()&&s1.top()==s[i]) s1.pop();
        else s1.push(s[i]);
    }
    
    if(s1.empty()) return 1;
    return 0;
}