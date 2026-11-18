#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cassert>
#include <unordered_map>
using namespace std;
typedef pair<int,int> pii;
unordered_map<string,int> m1;

vector<int> solution(int n, vector<string> words) {
    
    int cnt=0;
    
    vector<int> answer;
    char c=words[0][0];
    for(int i=0;i<words.size();i++){
        string w=words[i];
        if(m1[w]>0||w[0]!=c||w.size()==1){
            int ret1=(i%n)+1;
            answer.push_back(ret1);
            answer.push_back(i/n+1);
            return answer;
        }
        m1[w]++;
        c=w.back();
    }
    answer.push_back(0);
    answer.push_back(0);
    

    return answer;
}