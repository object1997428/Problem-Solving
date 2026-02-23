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

long long solution(int k, int d) {
    
    ll dd=pow(d,2), kk=pow(k,2);
    ll cnt=0;
    for(ll a=0;a*k<=d;a++){
        
        ll a2k2=pow(a,2)*kk;
        ll y=(ll)sqrt((dd-a2k2)/(double)kk);
        // cout<<"dd: "<<dd<<" a2k2: "<<a2k2<<" kk: "<<kk<<" y: "<<y<<endl;
        cnt+=y+1;
    }
    
    long long answer = cnt;
    return answer;
}