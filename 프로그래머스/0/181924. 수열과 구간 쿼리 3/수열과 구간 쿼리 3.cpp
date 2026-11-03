#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    for(int i=0;i<queries.size();i++){
        int a=queries[i][0];
        int b=queries[i][1];
        swap(arr[a],arr[b]);
    }
    
    vector<int> answer;
    for(int i=0;i<arr.size();i++){
        answer.push_back(arr[i]);
    }
    return answer;
}