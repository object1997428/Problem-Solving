#include <string>
#include <vector>
#include <string.h>
#include <climits>
#include <algorithm>
using namespace std;

int cnt[31];

int solution(vector<string> strArr) {
    
    int answer = 0;
    for(string str:strArr){
        int sz=str.size();
        cnt[sz]++;
        answer=max(answer,cnt[sz]);
    }
    
    
    
    
    return answer;
}