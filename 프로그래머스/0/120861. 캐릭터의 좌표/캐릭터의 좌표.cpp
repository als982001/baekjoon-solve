#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer(2, 0);
    
    int maxWidthLen = board[0] / 2;
    int minWidthLen = -maxWidthLen;
    int maxVerticalLen = board[1] / 2;
    int minVerticalLen = -maxVerticalLen;
    
    for (string dir : keyinput)
    {
        if (dir == "left")
        {
            if (answer[0] - 1 >= minWidthLen)
                --answer[0];
        }
        else if (dir == "right")
        {
            if (answer[0] + 1 <= maxWidthLen)
                ++answer[0];
        }
        else if (dir == "down")
        {
            if (answer[1] - 1 >= minVerticalLen)
                --answer[1];
        }
        else if (dir == "up")
        {
            if (answer[1] + 1 <= maxVerticalLen)
                ++answer[1];
        }
    }
    
    return answer;
}