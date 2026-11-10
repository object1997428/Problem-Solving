#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    
    int s=-1;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==2){
            s=i; break;
        }
    }
    
    int e=-1;
    for(int i=arr.size()-1;i>=0;i--){
        if(arr[i]==2){
            e=i; break;
        }
    }
    
    
    vector<int> answer;
    if(s==e&&e==-1) return {-1};
    for(int i=s;i<=e;i++){
        answer.push_back(arr[i]);
    }
    
    return answer;
}