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

vector<int> emoticons;
vector<vector<int>> users;
int discount[8];
int N,M;
int ans1,ans2;

void pick(int cnt){
    if(cnt==M){
        int sum1=0, sum2=0;
        for(int i=0;i<N;i++){
            int price=0;
            for(int j=0;j<M;j++){
                if(discount[j]>=users[i][0]){
                    price+=(1-discount[j]*0.01)*emoticons[j];
                }
            }
            if(price>=users[i][1]) sum1++;
            else sum2+=price;
        }
        // cout<<"ans1: "<<ans1<<" ans2: "<<ans2<<" sum1: "<<sum1<<" sum2: "<<sum2<<endl;
        if(ans1<sum1){
            ans1=sum1, ans2=sum2;
        }
        else if(ans1==sum1){
            ans2=max(ans2,sum2);
        }
        return;
    }
    
    for(int i=10;i<=40;i+=10){
        discount[cnt]=i;
        pick(cnt+1);
        discount[cnt]=0;
    }
}

vector<int> solution(vector<vector<int>> _users, vector<int> _emoticons) {
    //init
    users=_users;
    emoticons=_emoticons;
    N=users.size(), M=emoticons.size();
    
    //solve
    ans1=INT_MIN, ans2=INT_MIN;
    pick(0);
    
    
    vector<int> answer;
    answer.push_back(ans1);
    answer.push_back(ans2);
    return answer;
}