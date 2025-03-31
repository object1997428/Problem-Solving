#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cassert>
#include <cmath>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define endl '\n'

int score[27];
int N;
vector<char> v[4];

string solution(vector<string> survey, vector<int> choices) {
    N=survey.size();
    for(int i=0;i<N;i++){
        char l=survey[i][0], r=survey[i][1];
        int c=choices[i];
        
        if(c<=3) score[l-'A']+=abs(c-4);
        else score[r-'A']+=abs(c-4);
        
        // cout<<"score["<<l<<"]: "<<score[l-'A']<<" score["<<r<<"]: "<<score[r-'A']<<endl;
    }

    
    string answer = "";
    if(score['R'-'A']>=score['T'-'A']) answer.push_back('R');
    else answer.push_back('T');
    if(score['C'-'A']>=score['F'-'A']) answer.push_back('C');
    else answer.push_back('F');
    if(score['J'-'A']>=score['M'-'A']) answer.push_back('J');
    else answer.push_back('M');
    if(score['A'-'A']>=score['N'-'A']) answer.push_back('A');
    else answer.push_back('N');
    
    return answer;
}