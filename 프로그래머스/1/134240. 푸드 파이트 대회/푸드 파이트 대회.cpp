#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <climits>
#include <cassert>
#include <iostream>
#include <cmath>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

string solution(vector<int> food) {
    int N=food.size();
    string s="";
    
    for(int i=1;i<N;i++){
        int num=i;
        int half=floor(food[i]/2);
        for(int j=0;j<half;j++){
            s+=to_string(num);
        }
        
    }
    string answer = s+'0';
    // cout<<"answer: "<<answer<<endl;
    reverse(s.begin(),s.end());
    answer += s;
    // cout<<"answer: "<<answer<<endl;
    
    
    return answer;
}