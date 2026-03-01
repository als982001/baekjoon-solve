#include <string>
#include <vector>
#include <deque>

#define SHIFT_ONE "ShiftRow"
#define ROTATE "Rotate"

using namespace std;

int R, C;

deque<int> leftCol; // 행의 가장 왼쪽 부분들 (0번째 값)
deque<int> rightCol; // 행의 가장 오른쪽 부분들 (마지막 값)
deque<deque<int>> midRows; // 행의 왼쪽, 오른쪽 뺀 나머지 부분들

void ShiftRow()
{   
    leftCol.push_front(leftCol.back());
    leftCol.pop_back();
    
    rightCol.push_front(rightCol.back());
    rightCol.pop_back();
    
    // 깊은 복사 대신 이동(Move) 연산을 사용하여 완벽한 O(1) 보장
    midRows.push_front(move(midRows.back()));
    midRows.pop_back();
}

void Rotate()
{   
    // 행이 2개인 경우는 midRows를 신경쓰지 않아도 된다. (없기 때문)
    if (C == 2)
    {
        rightCol.push_front(leftCol.front());
        leftCol.pop_front();
        
        leftCol.push_back(rightCol.back());
        rightCol.pop_back();
        return;
    }
   
    // 1. 윗줄: leftCol 위 -> midRows 위쪽 앞으로 이동
    midRows[0].push_front(leftCol.front());    
    leftCol.pop_front();
    
    // 2. 오른쪽: midRows 위쪽 맨 뒤 -> rightCols 위
    rightCol.push_front(midRows.front().back());
    midRows.front().pop_back();
    
    // 3. 아랫줄: rightCol 아래 -> midRows 아래쪽 맨 뒤
    midRows.back().push_back(rightCol.back());
    rightCol.pop_back();
    
    // 왼쪽: midRows 아래쪽 앞 -> leftCol 아래
    leftCol.push_back(midRows.back().front());
    midRows.back().pop_front();
}

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    vector<vector<int>> answer;
    
    // 초기화
    leftCol.clear();
    rightCol.clear();
    midRows.clear();
    
    R = rc.size();
    C = rc[0].size();
    
    for (vector<int> rcInfo : rc)
    {
        leftCol.push_back(rcInfo[0]);
        rightCol.push_back(rcInfo.back());
        
        deque<int> midRow;
        
        for (int c = 1; c < C - 1; ++c)
            midRow.push_back(rcInfo[c]);
        midRows.push_back(midRow);
    }
    
    for (string operation : operations)
    {
        if (operation == SHIFT_ONE)
            ShiftRow();
        else if (operation == ROTATE)
            Rotate();
    }
    
    for (int r = 0; r < R; ++r)
    {
        vector<int> row;
            
        row.push_back(leftCol[r]);
        
        for (int item : midRows[r])
            row.push_back(item);    
        
        row.push_back(rightCol[r]);
        
        answer.push_back(row);
    }
    
    
    return answer;
}