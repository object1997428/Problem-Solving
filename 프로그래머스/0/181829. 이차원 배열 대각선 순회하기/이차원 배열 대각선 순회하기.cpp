#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, int k) {
    int answer = 0;
    int N,M;
    N=board.size(), M=board[0].size();
    
    for(int i=0;i<N;i++)for(int j=0;j<M;j++){
        if(i+j<=k){
            answer+=board[i][j];
        }
    }
    
    
    return answer;
}