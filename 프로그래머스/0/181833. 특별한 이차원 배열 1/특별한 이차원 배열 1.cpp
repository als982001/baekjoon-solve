#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    
    for (int r = 0; r < n; ++r)
    {
        vector<int> row;
        
        for (int c = 0; c < n; ++c)
        {
            if (r == c)
                row.push_back(1);
            else
                row.push_back(0);
        }
        
        answer.push_back(row);
    }
    
    return answer;
}