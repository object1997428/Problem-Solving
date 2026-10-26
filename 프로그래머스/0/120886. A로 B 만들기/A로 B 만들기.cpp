#include <string>
#include <vector>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

int cnt[27];
int cnt2[27];

int solution(string before, string after) {
    for(int i=0;i<before.size();i++){
        char c=before[i];
        cnt[c-'a']++;
    }
    
    for(int i=0;i<after.size();i++){
        char c=after[i];
        cnt2[c-'a']++;
    }
    
    for(int i=0;i<27;i++){
        if(cnt[i]!=cnt2[i]) return 0;
    }
    
    return 1;
}