#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> arr) {
    int i;
    for(i=0;pow(2,i)<arr.size();i++){
        int x=pow(2,i);
        if(x>=arr.size()) break;
    }
    
    int plus=pow(2,i)-arr.size();
    
    vector<int> answer;
    for(i=0;i<arr.size();i++) answer.push_back(arr[i]);
    for(i=0;i<plus;i++){
        answer.push_back(0);
    }

    return answer;
}