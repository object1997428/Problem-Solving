#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> s) {
    vector<string> answer;
    
    for (string str : s) {
        string temp = ""; // "110"을 모두 제거하고 남을 문자열 (스택 역할)
        int count110 = 0; // 뽑아낸 "110"의 개수
        
        // 1. 한 글자씩 넣으면서 끝부분이 "110"이 되면 즉시 뽑아냄 -> O(N)
        for (char c : str) {
            temp += c;
            if (temp.size() >= 3 && temp.substr(temp.size() - 3) == "110") {
                temp.erase(temp.size() - 3); // 뒤의 3글자("110") 제거
                count110++;
            }
        }
        
        // 2. 남은 문자열(temp)에서 가장 마지막에 나오는 '0'의 위치 찾기
        int lastZeroIdx = temp.find_last_of('0');
        
        // 3. 뽑아낸 개수만큼 "110" 뭉치 만들기
        string bundle = "";
        for (int i = 0; i < count110; i++) {
            bundle += "110";
        }
        
        // 4. 마지막 '0' 바로 뒤에 "110" 뭉치를 한 번에 삽입
        if (lastZeroIdx == string::npos) {
            // '0'이 하나도 없다면 (전부 '1'뿐이라면) 맨 앞에 붙임
            answer.push_back(bundle + temp);
        } else {
            // 마지막 '0' 바로 뒤(lastZeroIdx + 1)에 끼워 넣음
            answer.push_back(temp.substr(0, lastZeroIdx + 1) + bundle + temp.substr(lastZeroIdx + 1));
        }
    }
    
    return answer;
}