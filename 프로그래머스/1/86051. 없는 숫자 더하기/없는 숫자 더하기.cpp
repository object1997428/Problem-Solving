#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cmath>
#include <cassert>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int chk[10];

int solution(vector<int> numbers) {
    
    for(int i=0;i<numbers.size();i++){
        int x=numbers[i];
        chk[x]=1;
    }
    
    int answer = 0;
    for(int i=0;i<10;i++){
        if(chk[i]==0) answer+=i;
    }
    
    
    return answer;
}