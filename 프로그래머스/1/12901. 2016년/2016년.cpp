#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <climits>
#include <cassert>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int cnt[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
string s[7]={"FRI","SAT","SUN","MON","TUE","WED","THU"};

string solution(int a, int b) {
    int curIdx=6;
    for(int i=1;i<=a;i++){
        for(int j=1;j<=cnt[i];j++){
            curIdx=(curIdx+1)%7;
            if(i==a&&j==b) break;
        }
    }
    
    string answer = s[curIdx];
    return answer;
}