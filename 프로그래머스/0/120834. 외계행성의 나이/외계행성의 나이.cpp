#include <string>
#include <vector>

using namespace std;

string solution(int age) {
    string answer = "";
    
    string s=to_string(age);
    for(int i=0;i<s.size();i++){
        char c=s[i];
        answer+=(c-'0')+'a';
    }
    
    return answer;
}