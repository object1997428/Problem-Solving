#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef pair<int,int> pii;


unordered_map<char,int> m1;
string solution(string my_string) {
    
    string answer = "";
    for(int i=0;i<my_string.size();i++){
        char c=my_string[i];
        if(m1[c]>0) continue;
        m1[c]++;
        
        answer+=c;
    }
    
    
    
    return answer;
}