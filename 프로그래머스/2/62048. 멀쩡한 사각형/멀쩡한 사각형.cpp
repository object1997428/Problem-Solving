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

long long solution(int w,int h) {
    
    ll cnt=0;
    for(double i=1;i<=h;i++){
        ll sx=ceil(w*(h-i+1)/h);
        ll ex=floor(w*(h-i)/h);
        // cout<<"sx: "<<sx<<" ex: "<<ex<<endl;
        ll plus=sx-ex;
        cnt+=plus;
        // cout<<"plus: "<<plus<<" cnt: "<<cnt<<endl;
    }
    
    cnt=w*(ll)h-cnt;
    long long answer = cnt;
    return answer;
}