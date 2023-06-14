#include <string>
#include <vector>

using namespace std;

int blankNum = 0;
int keyR, keyC;
int lockR, lockC;
vector<vector<int>> wideLock;

vector<vector<int>> Rotate(vector<vector<int>> key)
{
    vector<vector<int>> rotated = key;
    
    for (int r = 0, kC = 0; r < rotated.size(); ++r, ++kC)
    {
        for (int c = 0, kR = key.size() - 1; c < rotated[r].size(); ++c, --kR)
            rotated[r][c] = key[kR][kC];
    }
    
    return rotated;
}

bool Check(int startR, int startC, vector<vector<int>> key)
{
    int leftBlankNum = blankNum;
    
    for (int r = 0, wideR = startR; r < keyR; ++r, ++wideR)
    {
        for (int c = 0, wideC = startC; c < keyC; ++c, ++wideC)
        {
            if (key[r][c] == 1 && wideLock[wideR][wideC] == 1)
                return false;
            
            if (key[r][c] == 1 && wideLock[wideR][wideC] == 0)
                --leftBlankNum;
        }
    }
    
    return leftBlankNum == 0;
}

bool CanFill(vector<vector<int>> key)
{    
    for (int startR = 0; startR <= wideLock.size() - keyR; ++startR)
    {
        for (int startC = 0; startC <= wideLock[0].size() - keyC; ++startC)
        {
            bool success = Check(startR, startC, key);
            
            if (success)
                return true;
        }
    }
    
    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    
    keyR = key.size(), keyC = key[0].size();
    lockR = lock.size(), lockC = lock[0].size();
    wideLock.resize((lockR + keyR + keyR) - 2, vector<int>((lockC + keyC + keyC) - 2, -1));
    
    for (int r = 0, wideR = keyR - 1; r < lockR; ++r, ++wideR)
    {
        for (int c = 0, wideC = keyC - 1; c < lockC; ++c, ++wideC)
        {
            wideLock[wideR][wideC] = lock[r][c];
            
            if (lock[r][c] == 0)
                ++blankNum;
        }
    }
    
    for (int i = 0; i < 4; ++i)
    {
        answer = CanFill(key);
        
        if (answer == true)
            break;
        else
            key = Rotate(key);
    }
    
    
    return answer;
}