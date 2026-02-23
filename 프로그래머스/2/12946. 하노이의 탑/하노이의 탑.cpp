#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cassert>
#include <cmath>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define endl '\n'

vector<vector<int>> answer;

void move(int from, int to, int tmp, int cnt){
    if(cnt==1){
        vector<int> v1;
        v1.push_back(from);
        v1.push_back(to);
        answer.push_back(v1);
        return;
    }
    
    move(from, tmp, to, cnt-1);
    move(from, to, tmp, 1);
    move(tmp, to, from, cnt-1);
}

vector<vector<int>> solution(int n) {
    move(1,3,2,n);
    
    return answer;
}