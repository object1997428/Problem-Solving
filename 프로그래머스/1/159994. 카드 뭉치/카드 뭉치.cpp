#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>
#include <string.h>
#include <cmath>
#include <cassert>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int cur1=0, cur2=0;
    int N=cards1.size(),M=cards2.size();
    
    for(int i=0;i<goal.size();i++){
        string x=goal[i];
        if(cur1<N&&cards1[cur1]==x) cur1++;
        else if(cur2<M&&cards2[cur2]==x) cur2++;
        else return "No";
    }
    
    return "Yes";
}