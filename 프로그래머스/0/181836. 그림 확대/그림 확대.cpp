#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> picture, int k) {
    vector<string> answer;
    
    for (int r = 0; r < picture.size(); ++r)
    {
        string row = picture[r];
        string newRow = "";
        
        for (int c = 0; c < row.size(); ++c)
        {
            char letter = row[c];
            
            for (int t = 0; t < k; ++t)
                newRow += letter;
        }
        
        for (int t = 0; t < k; ++t)
            answer.push_back(newRow);
    }
    
    return answer;
}