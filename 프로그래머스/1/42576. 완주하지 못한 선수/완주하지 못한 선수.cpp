#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <climits>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <unordered_map>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

unordered_map<string,int> m1;

string solution(vector<string> participant, vector<string> completion) {
    
    for(string s:completion){
        m1[s]++;
    }
    
    for(string s:participant){
        if(m1[s]--==0) return s;
    }
    
    return "";
}