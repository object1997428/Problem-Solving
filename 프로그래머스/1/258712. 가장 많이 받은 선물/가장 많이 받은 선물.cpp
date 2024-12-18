#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <climits>
#include <cassert>
#include <unordered_map>
using namespace std;

unordered_map<string,int> m1;
int N,M;
int record[51][51];
int score[51];
int cnt[51];
vector<string> split(string str){
    vector<string> ret;
    char* p=strtok((char*)str.c_str()," ");
    while(p){
        ret.push_back(p);
        p=strtok(NULL," ");
    }
    return ret;
}


int solution(vector<string> friends, vector<string> gifts) {
    //init
    N=friends.size(),M=gifts.size();
    for(int i=0;i<friends.size();i++){
        string name=friends[i];
        m1[name]=i+1;
    }
    
    for(int i=0;i<M;i++){
        auto v=split(gifts[i]);
        string A=v[0], B=v[1];
        int a=m1[A],b=m1[B];
        record[a][b]++;
        score[a]++; score[b]--;
    }
    //계산하기
    int ans=INT_MIN;
    for(int i=1;i<=N;i++)for(int j=i+1;j<=N;j++){
        if(i==j) continue;
        if(record[i][j]>record[j][i]) cnt[i]++;
        else if(record[i][j]<record[j][i]) cnt[j]++;
        else{
            if(score[i]>score[j]) cnt[i]++;
            else if(score[i]<score[j]) cnt[j]++;
        }
        ans=max(ans,cnt[i]);
        ans=max(ans,cnt[j]);
    }
    
    int answer = ans;
    return answer;
}