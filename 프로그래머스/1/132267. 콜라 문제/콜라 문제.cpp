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

int solution(int a, int b, int n) {
    
    int have=n;
    int received=0;
    while(have>=2){
        // cout<<"have: "<<have<<endl;
        int k=(have/a); //a를 k만큼 줄 수 있음
        if(k<=0) break;
        int plus=k*b;
        received+=plus;
        have=have-a*k+plus;
        // cout<<"k: "<<k<<" minus: "<<a*k<<" plus: "<<plus<<" have: "<<have<<endl;
    }
    
    int answer = received;
    return answer;
}