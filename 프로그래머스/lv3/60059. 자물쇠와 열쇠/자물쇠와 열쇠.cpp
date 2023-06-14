#include <string>
#include <vector>

using namespace std;

int blankNum = 0;               // 자물쇠의 홈의 개수
int keyR, keyC;                 // 키의 행 길이, 열 길이
int lockR, lockC;               // 자물쇠의 행 길이, 열 길이
vector<vector<int>> wideLock;   // 자물쇠의 확장판

// 키를 회준시키는 함수
vector<vector<int>> Rotate(vector<vector<int>> key)
{
    vector<vector<int>> rotated = key;
    
    for (int r = 0, kC = 0; r < rotated.size(); ++r, ++kC)
    {
        for (int c = 0, kR = key.size() - 1; c < rotated[r].size(); ++c, --kR)
            rotated[r][c] = key[kR][kC];
    }
    
    return rotated; // 회전된 키를 반환한다.
}

// 현재 시작 좌표에서 키가 모든 홈을 매울 수 있는지 검사하는 함수
bool Check(int startR, int startC, vector<vector<int>> key)
{
    int leftBlankNum = blankNum;    // 남은 홈의 개수
    
    for (int r = 0, wideR = startR; r < keyR; ++r, ++wideR)
    {
        for (int c = 0, wideC = startC; c < keyC; ++c, ++wideC)
        {   
            // 문제의 조건
            // 자물쇠 영역 내에서는 열쇠의 돌기 부분과 자물쇠의 홈 부분이 정확히 일치해야 하며 열쇠의 돌기와 자물쇠의 돌기가 만나서는 안됩니다.
            if (key[r][c] == 1 && wideLock[wideR][wideC] == 1)
                return false;
            
            // 키의 돌기 + 자물쇠의 홈
            if (key[r][c] == 1 && wideLock[wideR][wideC] == 0)
                --leftBlankNum;
        }
    }
    
    return leftBlankNum == 0;   // 남은 홈의 개수가 0일 경우 true, 아니면 false
}

// 자물쇠 확장판에서 시작 좌표를 지정하여
// 모든 홈을 매울 수 있는지 검사하는 함수
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
    
    // 확장된 자물쇠를 만드는 과정
    wideLock.resize((lockR + keyR + keyR) - 2, vector<int>((lockC + keyC + keyC) - 2, -1));
        
    for (int r = 0, wideR = keyR - 1; r < lockR; ++r, ++wideR)
    {
        for (int c = 0, wideC = keyC - 1; c < lockC; ++c, ++wideC)
        {
            wideLock[wideR][wideC] = lock[r][c];
            
            // 만약 홈이라면 홈의 개수를 증가시킨다.
            if (lock[r][c] == 0)
                ++blankNum;
        }
    }
    
    // 키의 모양이 정사각형이기에
    // 4번 회전하면 원래대로 돌아온다.
    // 그렇기에 4번 반복한다.
    for (int i = 0; i < 4; ++i)
    {
        answer = CanFill(key); 
        
        if (answer == true)
            break;              // 만약 현재 키로 자물쇠의 모든 홈을 매울 수 있는 경우
        else
            key = Rotate(key);  // 못 매울 경우 회전시킨다.
    }
    
    
    return answer;
}