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

int way[4][2]={{-1,0},{0,1},{1,0},{0,-1}};


int solution(vector<vector<string>> board, int y, int x) {
    int cnt=0;
    int N=board.size(), M=board[0].size();
    for(int w=0;w<4;w++){
        int ny=y+way[w][0];
        int nx=x+way[w][1];
        
        if(ny>=0&&nx>=0&&ny<N&&nx<M&&board[y][x]==board[ny][nx]){
            cnt++;
        }
    }
    
    
    int answer = cnt;
    return answer;
}