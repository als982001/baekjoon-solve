#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    for (int width = yellow; width >= 1; --width)
    {
        if (yellow % width > 0)
            continue;
        
        int height = yellow / width;
        
        int total = (width + 2) * (height + 2);
        int expectedBrown = total - yellow;
        
        if (brown == expectedBrown)
        {
            answer.push_back(width + 2);
            answer.push_back(height + 2);
            break;
        }
    }
    
    return answer;
}













/*

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    for (int width = 1; width * width <= yellow; ++width)
    {
        if (yellow % width > 0)
            continue;
        
        int height = yellow / width;
        
        int currentBrown = (width + height) * 2 + 4;
        
        if (brown == currentBrown)
        {
            answer.push_back(height + 2);
            answer.push_back(width + 2);
            
            break;
        }
    }
    
    return answer;
}

*/