#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

vector<int> v1;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int N=progresses.size();
    for(int i=0;i<N;i++){
        int x=ceil((100-(double)progresses[i])/speeds[i]);
        v1.push_back(x);
        cout<<x<<" ";
    }
    cout<<endl;
    
    vector<int> answer;
    
    int maxD=v1[0];
    answer.push_back(1);
    for(int i=1;i<N;i++){
        if(maxD>=v1[i]) answer.back()++;
        else {
            maxD=v1[i];
            answer.push_back(1);
        }
    }
    
    
    
    return answer;
}