#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <climits>
#include <cmath>
#include <cassert>
#include <iostream>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define endl '\n'

int k;
bool comp(string& v1, string& v2){
    if(v1[k]==v2[k]) return v1<v2;
    return v1[k]<v2[k];
}

vector<string> solution(vector<string> strings, int n) {
    k=n;
    sort(strings.begin(),strings.end(),comp);
    
    
    vector<string> answer=strings;
    return answer;
}