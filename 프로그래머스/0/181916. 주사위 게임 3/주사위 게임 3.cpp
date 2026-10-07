#include <string>
#include <vector>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cassert>
#include <cmath>
#include <unordered_map>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

unordered_map<int,int> m1;
vector<int> v1;


int solution(int a, int b, int c, int d) {
    //미리 정렬시켜놓기
    v1.push_back(a);
    v1.push_back(b);
    v1.push_back(c);
    v1.push_back(d);
    sort(v1.begin(),v1.end());
    
    m1[a]++; m1[b]++; m1[c]++; m1[d]++;
    
    //종류 개수 찾기
    int typeCnt=m1.size();
    cout<<"typeCnt: "<<typeCnt<<endl;
    
    //조건분기
    if(typeCnt==1) return 1111*a;
    else if(typeCnt==2){
        int p=v1[0], q=v1[3];
        if(m1[p]==2) return abs(p-q)*(p+q);
        else if(m1[p]==3){
            return pow(10*p+q,2);
        }
        else if(m1[q]==3){
            return pow(10*q+p,2);
        }
    }
    else if(typeCnt==4){
        return v1[0];
    }
    else {
        if(m1[v1[0]]==2) return v1[2]*v1[3];
        else if(m1[v1[1]]==2) return v1[0]*v1[3];
        else if(m1[v1[2]]==2) return v1[0]*v1[1];
    }
    
    
    int answer = 0;
    return answer;
}