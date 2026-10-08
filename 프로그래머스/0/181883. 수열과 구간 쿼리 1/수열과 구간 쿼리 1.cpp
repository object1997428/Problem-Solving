#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    

    int N,M;
    N=queries.size();
    for(int i=0;i<N;i++){
        int s=queries[i][0];
        int e=queries[i][1];
        
        for(int j=s;j<=e;j++) arr[j]++;
    }
    
    vector<int> answer;
    answer=arr;
    
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return answer;
}