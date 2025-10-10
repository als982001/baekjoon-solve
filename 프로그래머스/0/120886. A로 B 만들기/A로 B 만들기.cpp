#include <string>
#include <vector>
#include <map>

#define CAN_MAKE 1
#define CAN_NOT_MAKE 0

using namespace std;

int solution(string before, string after) {
    int answer = CAN_MAKE;
    
    map<char, int> letterCounts;
    
    for (char letter : before)
    {
        letterCounts[letter] += 1;
    }
    
    for (int i = 0; i < after.size(); ++i)
    {
        char letter = after[i];
        
        letterCounts[letter] = letterCounts[letter] - 1;
        
        if (letterCounts[letter] < 0)
        {
            answer = CAN_NOT_MAKE;
            break;
        }
    }
    
    
    return answer;
}