#include <string>
#include <vector>

using namespace std;

int Pick(vector<vector<int>>& board, int line)
{
    int doll = 0;
    
    for (int r = 0; r < board.size(); ++r)
    {
        if (board[r][line] > 0)
        {
            doll = board[r][line];
            board[r][line] = 0;
            
            break;
        }
    }
    
    return doll;
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    vector<int> basket;
    
    for (int m = 0; m < moves.size(); ++m)
    {
        int move = moves[m];
        
        int doll = Pick(board, move - 1);
    
        if (doll > 0)
        {
            if (basket.size() == 0 || basket.back() != doll)
                basket.push_back(doll);
            else
            {
                answer += 2;
                basket.pop_back();
            }
        }
    }
    
    
    return answer;
}
