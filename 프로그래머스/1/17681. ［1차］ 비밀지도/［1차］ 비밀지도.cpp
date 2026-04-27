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

int N;
string printX(int x){
    string ret="";
    while(x){
        int k=x%2;
        if(k==1) ret='#'+ret;
        else ret=' '+ret;
        x/=2;
    }
    while(ret.size()<N) ret=' '+ret;
    
    return ret;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    N=n;
    vector<string> answer;
    
    for(int i=0;i<n;i++){
        //i열 구하기
        int x=arr1[i]|arr2[i];
        string ret=printX(x);
        answer.push_back(ret);
    }
    
    
    
    
    return answer;
}