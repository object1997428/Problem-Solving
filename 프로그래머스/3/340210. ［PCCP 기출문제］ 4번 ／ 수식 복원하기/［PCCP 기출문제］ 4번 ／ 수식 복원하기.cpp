#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <climits>
#include <cassert>
#include <cmath>
using namespace std;

vector<string> vx,v;
vector<int> cands;

vector<string> split(string s){
    vector<string> ret;
    char* p=strtok((char*)s.c_str()," ");
    while(p){
        ret.push_back(p);
        p=strtok(NULL," ");
    }
    return ret;
}

bool valid(string exp, int k){
    auto e=split(exp);
    // for(auto x:e) cout<<x<<" "; cout<<endl;
    int a=stoi(e[0]), b=stoi(e[2]), c=stoi(e[4]);
    char cal=e[1][0];
    
    int a1=a/10, a2=a%10, b1=b/10, b2=b%10;
    int c1=c/100, c2=(c%100)/10, c3=(c%100)%10;
    // cout<<"b2: "<<b2<<" k: "<<k<<endl;
    if(a1>=k||a2>=k||b1>=k||b2>=k||c1>=k||c2>=k||c3>=k) return false;
    
    if(cal=='+') return (a1*k+a2)+(b1*k+b2)==(c1*k*k+c2*k+c3);
    return (a1*k+a2)-(b1*k+b2)==(c1*k*k+c2*k+c3);
}

bool validx(string exp, int k){
    auto e=split(exp);
    // for(auto x:e) cout<<x<<" "; cout<<endl;
    int a=stoi(e[0]), b=stoi(e[2]);
    char cal=e[1][0];
    
    int a1=a/10, a2=a%10, b1=b/10, b2=b%10;
    // cout<<"b2: "<<b2<<" k: "<<k<<endl;
    if(a1>=k||a2>=k||b1>=k||b2>=k) return false;
    return true;
}

int calculate(string exp,int k){
    auto e=split(exp);
    // for(auto x:e) cout<<x<<" "; cout<<endl;
    int a=stoi(e[0]), b=stoi(e[2]);
    char cal=e[1][0];
    
    int a1=a/10, a2=a%10, b1=b/10, b2=b%10;
    
    if(cal=='+'){
        int c=((a1*k+a2)+(b1*k+b2));
        int c1=(c/k)/k, c2=(c%(k*k))/k, c3=(c%(k*k))%k;
        return c1*100+c2*10+c3;
    }
    else {
        int c=((a1*k+a2)-(b1*k+b2));
        int c1=(c/k)/k, c2=(c%(k*k))/k, c3=(c%(k*k))%k;
        return c1*100+c2*10+c3;
    }
}

vector<string> solution(vector<string> expressions) {
    //x인 수식과 아닌 수식 구별해주기
    for(string exp:expressions){
        bool isX=false;
        for(int i=0;i<exp.size();i++) if(exp[i]=='X'){
            isX=true; break;
        }
        
        if(isX) vx.push_back(exp);
        else v.push_back(exp);
    }
    //후보 진법 넣기
    for(int i=2;i<=9;i++) cands.push_back(i);
    
    //solve
    //1. x아닌 수식에서 진법 후보 거르기
    for(string exp:v){
        for(int i=cands.size()-1;i>=0;i--){
            int k=cands[i]; //후보 진법
            if(!valid(exp, k)){
                cands.erase(cands.begin()+i);
            }
        }
    }
    for(string exp:vx){
        for(int i=cands.size()-1;i>=0;i--){
            int k=cands[i]; //후보 진법
            if(!validx(exp, k)){
                cands.erase(cands.begin()+i);
            }
        }
    }
    //2. x구하기
    vector<string> answer;
    for(string exp:vx){
        string x="-1";
        for(int k:cands){
            int ret=calculate(exp,k);
            string rettos=to_string(ret);
            // cout<<"exp: "<<exp<<" k: "<<k<<" ret: "<<ret<<endl;
            if(x=="-1") x=rettos;
            if(x!="-1"&&x!=rettos){
                x="?"; break;
            } 
        }
        
        if(x=="-1") cout<<"x가 -1이다, exp: "<<exp<<endl;
        for(int i=0;i<exp.size();i++){
            if(exp[i]=='X'){
                string e=exp.substr(0,i)+x;
                answer.push_back(e);
                break;
            }
        }
    }
    
    
    
    return answer;
}