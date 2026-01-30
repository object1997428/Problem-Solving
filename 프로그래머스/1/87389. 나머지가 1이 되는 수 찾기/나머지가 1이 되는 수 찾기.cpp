#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <climits>
#include <cassert>
#include <cmath>
#include <iostream>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int solution(int n) {
    
    for(int i=2;i<n;i++){
        if(n%i==1) return i;
    }
    
}