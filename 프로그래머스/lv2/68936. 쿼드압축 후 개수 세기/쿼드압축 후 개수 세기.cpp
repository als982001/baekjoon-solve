#include <string>
#include <vector>

using namespace std;

vector<vector<int>> board;

vector<int> Check(int startR, int startC, int len)
{  
    bool allSame = true;
    
    int num = board[startR][startC];
    
    for (int r = startR; r < startR + len; ++r)
    {
        for (int c = startC; c < startC + len; ++c)
        {
            if (board[r][c] != num)
            {
                allSame = false;
                break;
            }
        }
        
        if (allSame == false)
            break;
    }
    
    if (allSame)
    {
        if (num == 0)
            return { 1, 0 };
        else
            return { 0, 1 };
    }
    else
    {
        int nextLen = len / 2;
        
        vector<int> result(2, 0);
        
        vector<int> upperLeft = Check(startR, startC, len / 2);
        vector<int> upperRight = Check(startR, startC + nextLen, nextLen);
        vector<int> lowerLeft = Check(startR + nextLen, startC, nextLen);
        vector<int> lowerRight = Check(startR + nextLen, startC + nextLen, nextLen);
        
        result[0] += upperLeft[0];
        result[1] += upperLeft[1];
        
        result[0] += upperRight[0];
        result[1] += upperRight[1];
        
        result[0] += lowerLeft[0];
        result[1] += lowerLeft[1];
        
        result[0] += lowerRight[0];
        result[1] += lowerRight[1];
        
        return result;
    }
        
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    
    board = arr;
    
    return Check(0, 0, arr.size());
    
    return answer;
}