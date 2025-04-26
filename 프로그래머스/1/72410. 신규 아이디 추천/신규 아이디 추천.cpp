#include <string>
#include <vector>
#include <string.h>
#include <iostream>
#include <climits>
#include <cassert>
#include <cmath>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define endl '\n'

string solution(string str) {
    //1. 대->소
    for(int i=str.size()-1;i>=0;i--){
        char c=str[i];
        if(c>='A'&&c<='Z'){
            // cout<<"c: "<<c<<endl;
            str[i]=c-'A'+'a';
        }
    }
    //2. 규칙에 안맞는 문자 지우기
    for(int i=str.size()-1;i>=0;i--){
        char c=str[i];
        if((c>='a'&&c<='z')||(c>='0'&&c<='9')||c=='_'||c=='-'||c=='.'){}
        else{
            // cout<<"c: "<<c<<endl;
            // cout<<"전 str: "<<str<<endl;
            str.erase(str.begin()+i);
            // cout<<"후 str: "<<str<<endl;
        }
    }
    //3. .가 2번 이상 연속이면 하나의 .로 치환
    for(int i=str.size()-2;i>=0;i--){
        char c=str[i];
        if(c=='.'&&str[i+1]=='.'){
            // cout<<"전 str: "<<str<<endl;
            str.erase(str.begin()+i);
            // cout<<"후 str: "<<str<<endl;
        }
    }
    //4. 처음이나 끝에 .있으면 제거
    // cout<<"전 str: "<<str<<endl;
    if(!str.empty()&&str.back()=='.') str.pop_back();
    if(!str.empty()&&str[0]=='.') str=str.substr(1);
    // cout<<"후 str: "<<str<<endl;
    
    //5. 빈문자열이면 'a'
    if(str.empty()) str="a";
    // cout<<"후 str: "<<str<<endl;
    
    //6. 16글자 이상이면 자르기
    if(str.size()>=16) str=str.substr(0,15);
    if(!str.empty()&&str.back()=='.') str.pop_back();
    if(!str.empty()&&str[0]=='.') str=str.substr(1);
    // cout<<"후 str: "<<str<<endl;
    
    //7.2글자 이하면 3배
    while(str.size()<=2) str.push_back(str.back());
    
    string answer = str;
    return answer;
}