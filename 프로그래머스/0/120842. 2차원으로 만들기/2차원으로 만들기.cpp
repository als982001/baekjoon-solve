#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    vector<vector<int>> answer;
    
    vector<int> row;
    
    for (int i = 0; i < num_list.size(); ++i)
    {
        int num = num_list[i];
        
        row.push_back(num);
        
        if (row.size() == n)
        {
            answer.push_back(row);
            
            while(row.size() > 0)
                row.pop_back();
        }
    }
    
    return answer;
}