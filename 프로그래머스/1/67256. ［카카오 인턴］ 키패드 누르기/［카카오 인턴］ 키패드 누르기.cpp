#include <string>
#include <vector>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <cassert>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define endl '\n'

pii num2xy[10]={{3,1},{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}};

string solution(vector<int> numbers, string hand) {
    int ly=3,lx=0, ry=3,rx=2;
    
    string ans="";
    for(int k:numbers){
        if(k==1||k==4||k==7){
            ans+="L";
            ly=num2xy[k].first;
            lx=num2xy[k].second;
        }
        else if(k==3||k==6||k==9){
            ans+="R";
            ry=num2xy[k].first;
            rx=num2xy[k].second;
        }
        else{
            int ky=num2xy[k].first;
            int kx=num2xy[k].second;
            
            int lDist=abs(ky-ly)+abs(kx-lx);
            int rDist=abs(ky-ry)+abs(kx-rx);
            if(lDist<rDist||(lDist==rDist&&hand=="left")){
                ans+="L";
                ly=num2xy[k].first;
                lx=num2xy[k].second;
            }
            else if(lDist>rDist||(lDist==rDist&&hand=="right")){
                ans+="R";
                ry=num2xy[k].first;
                rx=num2xy[k].second;
            }
            else assert(0);
        }
    }
    
    
    string answer = ans;
    return answer;
}