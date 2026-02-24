#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <climits>
#include <cassert>
#include <cmath>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define endl '\n'

int ans,N,M;
int dp[1001][1001];

int solution(vector<vector<int>> board) //arr[i][j]=i,j가 만들수 있는 최대 정각사각형 길이
{
    int answer = 0;

    const int height = board.size(), width = board[0].size();

    for (int i = 0; i < width; ++i)
    {
        answer = std::max(answer, board[0][i]);
    }

    for (int i = 0; i < height; ++i)
    {
        answer = std::max(answer, board[i][0]);
    }

    for (int i = 1; i < height; ++i)
    {
        for (int j = 1; j < width; ++j)
        {
            if (board[i][j])
            {
                board[i][j] += std::min(board[i - 1][j], std::min(board[i][j - 1], board[i - 1][j - 1]));
                answer = std::max(answer, board[i][j]);
            }
        }
    }

    return answer * answer;
}