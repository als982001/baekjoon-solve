#include <string>
#include <vector>
#include <sstream>

#define MAX_LEN 50
#define MAX 2502
#define UPDATE "UPDATE"
#define MERGE "MERGE"
#define UNMERGE "UNMERGE"
#define PRINT "PRINT"
#define EMPTY "EMPTY"

using namespace std;

int parentCell[MAX];
string cellValue[MAX];

int CoordToIdx(int r, int c)
{
    return ((r - 1) * MAX_LEN) + c;
}

int GetParentCell(int idx)
{
    if (parentCell[idx] == idx)
        return idx;
    
    return GetParentCell(parentCell[idx]);
}

void UnionCell(int idx1, int idx2)
{
    int parent1 = GetParentCell(idx1);
    int parent2 = GetParentCell(idx2);
    
    if (parent1 == parent2)
        return;
    
    // 문제 조건 중 "두 셀 중 한 셀이 값을 가지고 있을 경우 병합된 셀은 그 값을 가지게 됩니다." 가 있는데, 
    // (r1, c1)에 값이 없고 (r2, c2)에 값이 있는 특이 케이스 대응
    if (cellValue[parent1] == EMPTY && cellValue[parent2] != EMPTY)
        cellValue[parent1] = cellValue[parent2];
    
    parentCell[parent2] = parent1;
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    
    // 초기화
    for (int r = 1; r <= MAX_LEN; ++r)
    {
        for (int c = 1; c <= MAX_LEN; ++c)
        {
            int idx = CoordToIdx(r, c);
            
            parentCell[idx] = idx;
            cellValue[idx] = EMPTY;
        }
    }
    
    for (string command : commands) 
    {
        stringstream ss(command);
        string segment;
        
        vector<string> commandInfo;
        
        while(getline(ss, segment, ' '))
            commandInfo.push_back(segment);
        
        string commandType = commandInfo[0];
        
        if (commandType == UPDATE)
        {
            // UPDATE r c value
            if (commandInfo.size() == 4)
            {
                int targetR = stoi(commandInfo[1]);
                int targetC = stoi(commandInfo[2]);
                string newValue = commandInfo[3];
                
                int parentCellIdx = GetParentCell(CoordToIdx(targetR, targetC));
                
                cellValue[parentCellIdx] = newValue;
            }
            else
            {
                // UPDATE value1 value2
                string targetValue = commandInfo[1];
                string newValue = commandInfo[2];
                
                for (int r = 1; r <= MAX_LEN; ++r)
                {
                    for (int c = 1; c <= MAX_LEN; ++c)
                    {
                        int parentCellIdx = GetParentCell(CoordToIdx(r, c));
                        
                        if (cellValue[parentCellIdx] == targetValue)
                            cellValue[parentCellIdx] = newValue;
                    }
                }
            }
        }
        else if (commandType == MERGE)
        {
            // MERGE r1 c1 r2 c2
            
            int r1 = stoi(commandInfo[1]);
            int c1 = stoi(commandInfo[2]);
            int r2 = stoi(commandInfo[3]);
            int c2 = stoi(commandInfo[4]);
            
            int idx1 = CoordToIdx(r1, c1);
            int idx2 = CoordToIdx(r2, c2);
            
            UnionCell(idx1, idx2);
        }
        else if (commandType == UNMERGE)
        {
            int targetR = stoi(commandInfo[1]);
            int targetC = stoi(commandInfo[2]);
            int unmergeTargetIdx = GetParentCell(CoordToIdx(targetR, targetC));
            
            string savedValue = cellValue[unmergeTargetIdx];
            
            vector<int> targetIdxes;
            
            for (int r = 1; r <= MAX_LEN; ++r)
            {
                for (int c = 1; c <= MAX_LEN; ++c)
                {
                    int idx = CoordToIdx(r, c);
                    int parentIdx = GetParentCell(idx);
                    
                    if (parentIdx == unmergeTargetIdx)
                        targetIdxes.push_back(idx);
                }
            }
            
            for (int targetIdx : targetIdxes)
            {
                parentCell[targetIdx] = targetIdx;
                cellValue[targetIdx] = EMPTY;
            }
            
            cellValue[CoordToIdx(targetR, targetC)] = savedValue;
        }
        else if (commandType == PRINT)
        {
            int targetR = stoi(commandInfo[1]);
            int targetC = stoi(commandInfo[2]);
            
            int idx = CoordToIdx(targetR, targetC);
            
            int parentCellIdx = GetParentCell(idx);
            
            answer.push_back(cellValue[parentCellIdx]);
        }
    }
    
    return answer;
}











/*

#include <string>
#include <vector>
#include <sstream>

#define MAX 50
#define EMPTY "EMPTY"

using namespace std;

int parentCell[2502];   // 표의 각 셀의 부모 셀
string cellValue[2502]; // 표의 셀마다 저장되어 있는 값

int GetParentCell(int cell)
{
    if (parentCell[cell] == cell)
        return cell;
    
    return GetParentCell(parentCell[cell]);
}

void UnionCells(int cell1, int cell2)
{
    int parent1 = GetParentCell(cell1);
    int parent2 = GetParentCell(cell2);
    
    if (parent1 == parent2)
        return;
    
    if (cellValue[parent1] == EMPTY && cellValue[parent2] != EMPTY)
        cellValue[parent1] = cellValue[parent2];
    
    // 병합된 셀은 (r1, c1) 위치의 셀 값을 가짐
    parentCell[parent2] = parent1;
}

int ConvertCoord(int r, int c)
{
    return (r - 1) * MAX + c; // 1 ~ 2500
}

using namespace std;

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    
    // 1. 초기화
    for (int cell = 1; cell <= 2500; ++cell)
    {
        cellValue[cell] = "EMPTY";
        parentCell[cell] = cell;
    }
    
    for (string command : commands)
    {
        stringstream ss(command);
        string segment;
        
        vector<string> commandInfo;
        
        while(getline(ss, segment, ' '))
            commandInfo.push_back(segment);
        
        if (commandInfo[0] == "UPDATE")
        {
            // 케이스1: UPDATE r c value
            if (commandInfo.size() == 4)
            {
                int r = stoi(commandInfo[1]);
                int c = stoi(commandInfo[2]);
                string newValue = commandInfo[3];
                
                int cell = ConvertCoord(r, c);
                
                int parentCell = GetParentCell(cell);
                cellValue[parentCell] = newValue;
            }
            // 케이스2: UPDATE value1 value2
            else
            {
                string targetValue = commandInfo[1];
                string newValue = commandInfo[2];
                
                for (int cell = 1; cell <= 2500; ++cell)
                {
                    int currentParentCell = GetParentCell(cell);
                    
                    if (cellValue[currentParentCell] == targetValue)
                        cellValue[currentParentCell] = newValue;
                }
            }
        }
        
        // 케이스3: MERGE r1 c1 r2 c2
        if (commandInfo[0] == "MERGE")
        {
            int r1 = stoi(commandInfo[1]);
            int c1 = stoi(commandInfo[2]);
            int r2 = stoi(commandInfo[3]);
            int c2 = stoi(commandInfo[4]);
            
            int cell1 = ConvertCoord(r1, c1);
            int cell2 = ConvertCoord(r2, c2);
            
            UnionCells(cell1, cell2);
        }
        
        // 케이스4: UNMERGE r c
        if (commandInfo[0] == "UNMERGE")
        {
            int r = stoi(commandInfo[1]);
            int c = stoi(commandInfo[2]);
            
            int targetCell = ConvertCoord(r, c); 
            int targetParentCell = GetParentCell(targetCell);
            
            string currentValue = cellValue[targetParentCell];
            
            vector<int> unmergeCells;
            
            for (int cell = 1; cell <= 2500; ++cell)
            {
                if (GetParentCell(cell) == targetParentCell)
                    unmergeCells.push_back(cell);
            }
            
            for (int cell : unmergeCells)
            {
                parentCell[cell] = cell;
                
                if (cell == targetCell)
                    cellValue[cell] = currentValue;
                else
                    cellValue[cell] = EMPTY;
            }
        }
        
        // 케이스5: PRINT r c
        if (commandInfo[0] == "PRINT")
        {
            int r = stoi(commandInfo[1]);
            int c = stoi(commandInfo[2]);
            int cell = ConvertCoord(r, c);
            
            int parentCell = GetParentCell(cell);
            
            answer.push_back(cellValue[parentCell]);
        }
        
    }
    
    return answer;
}

*/ 