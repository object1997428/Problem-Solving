#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cassert>
#include <cmath>
using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int n=bill[0],m=bill[1], N=wallet[0],M=wallet[1];
    if(n<=N&&m<=M) return 0;
    if(m<=N&&n<=M) return 0;
    for(int i=1;;i++){
        if(n<m) swap(n,m);
        
        n=floor(n/2);
        if(n<=N&&m<=M) return i;
        if(m<=N&&n<=M) return i;
    }
    
}