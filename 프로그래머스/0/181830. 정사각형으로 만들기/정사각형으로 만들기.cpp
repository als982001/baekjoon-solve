#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr) {
    vector<vector<int>> answer(arr);
    
    int row = arr.size();
    int col = arr[0].size();
    
    if (row < col)
    {
        vector<int> newRow(col, 0);
        
        while(answer.size() < answer[0].size())
            answer.push_back(newRow);
            
            
    }
    else if (row > col)
    {
        for (int r = 0; r < row; ++r)
        {
            while(answer[r].size() < row)
                answer[r].push_back(0);
                
        }
    }
    
    return answer;
}