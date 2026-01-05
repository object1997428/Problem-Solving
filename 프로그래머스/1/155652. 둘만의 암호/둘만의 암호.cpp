#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <climits>
#include <cmath>
#include <cassert>
#include <iostream>
#include <unordered_map>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

unordered_map<char,int> noCount;

string solution(string s, string skip, int index) {
    
    for(auto k:skip){
        noCount[k]=1;
    }
    
    int N=s.size();
    for(int i=0;i<N;i++){  
        int j=0, count=index;
        char nc=s[i];
        while(j++<count){
            nc=nc+1;
            if(nc>'z') nc=(nc-'z')+'a'-1;
            if(noCount[nc]==1) count++;
            
            cout<<"nc: "<<nc<<endl;
        }
        s[i]=nc;
       
    }
    
    
    
    
    string answer = s;
    return answer;
}