#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, int k) {
    int answer = 0;
    
    for (int r = 0; r < board.size(); ++r)
    {
        for (int c = 0; c < board[r].size(); ++c)
        {
            if (r + c <= k)
                answer += board[r][c];
        }
    }
    
    return answer;
}