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