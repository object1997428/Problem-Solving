#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <climits>
#include <cassert>
#include <cmath>
#include <queue>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;



string solution(string str) {
    //1. 
    for(int i=0;i<str.size();i++){
        if(str[i]>='A'&&str[i]<='Z') str[i]=str[i]-'A'+'a';
    }
    //2.
    for(int i=str.size()-1;i>=0;i--){
        if((str[i]>='a'&&str[i]<='z')||(str[i]>='0'&&str[i]<='9')||str[i]=='-'||str[i]=='_'||str[i]=='.'){}
        else{
            // cout<<"str: "<<str<<" str[i]: "<<str[i]<<endl;
            str.erase(str.begin()+i);
            // cout<<"str: "<<str<<endl;
        }
    }
    //3.
    for(int i=str.size()-1;i>=1;i--){
        if(str[i]=='.'&&str[i-1]==str[i]){
            // cout<<"str: "<<str<<" str[i]: "<<str[i]<<endl;
            str.erase(str.begin()+i);
            // cout<<"str: "<<str<<endl;
        }
    }
    //4. 
    if(!str.empty()&&str[0]=='.') str.erase(str.begin());
    if(!str.empty()&&str.back()=='.') str.pop_back();
    
    //5.
    if(str.size()==0) str="a";
    
    //6.
    if(str.size()>=16){
        str=str.substr(0,15);
        if(str.back()=='.') str.pop_back();
        // cout<<"str.size(): "<<str.size()<<endl;
    }
    
    //7.
    while(str.size()<=2){
        str.push_back(str.back());
    }
    
    
    string answer = str;
    return answer;
}