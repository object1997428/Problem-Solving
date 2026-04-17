#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <climits>
#include <cassert>
#include <cmath>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int N;
int arr[10001][3];

vector<int> solution(vector<int> answers) {
    
    N=answers.size();
    arr[0][0]=1, arr[1][0]=2, arr[2][0]=3, arr[3][0]=4, arr[4][0]=5;
    arr[0][1]=2, arr[1][1]=1, arr[2][1]=2, arr[3][1]=3, arr[4][1]=2, arr[5][1]=4, arr[6][1]=2, arr[7][1]=5;
    arr[0][2]=3, arr[1][2]=3, arr[2][2]=1, arr[3][2]=1, arr[4][2]=2, arr[5][2]=2, arr[6][2]=4, arr[7][2]=4, arr[8][2]=5, arr[9][2]=5;
    for(int i=5;i<N;i++){
        arr[i][0]=arr[i-5][0];
    }
    for(int i=8;i<N;i++){
        arr[i][1]=arr[i-8][1];
    }
    for(int i=10;i<N;i++){
        arr[i][2]=arr[i-10][2];
    }
    
    
    
    int cnt1,cnt2,cnt3;
    cnt1=cnt2=cnt3=0;
    for(int i=0;i<N;i++){
        if(arr[i][0]==answers[i]) cnt1++;
        if(arr[i][1]==answers[i]) cnt2++;
        if(arr[i][2]==answers[i]) cnt3++;
    }
    
    
    vector<pii> v1;
    v1.push_back({cnt1,-1});
    v1.push_back({cnt2,-2});
    v1.push_back({cnt3,-3});
    sort(v1.begin(),v1.end(),greater<>());
    
    
    
    vector<int> answer;
    answer.push_back(v1[0].second*(-1));
    if(v1[1].first==v1[0].first) answer.push_back(v1[1].second*(-1));
    if(v1[2].first==v1[0].first) answer.push_back(v1[2].second*(-1));
    
    return answer;
}