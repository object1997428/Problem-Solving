#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <climits>
#include <cassert>
#include <cmath>
#include <iostream>
#include <unordered_map>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

unordered_map<string,int> m1;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    
    int N=name.size();
    for(int i=0;i<N;i++){
        string n=name[i];
        int v=yearning[i];
        m1[n]=v;
    }
    
    for(auto arr:photo){
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=m1[arr[i]];
        }
        // cout<<"sum: "<<sum<<endl;
        answer.push_back(sum);
    }
    
    
    
    return answer;
}