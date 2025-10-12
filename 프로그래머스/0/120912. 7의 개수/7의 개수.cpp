#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    
    for (int num : array)
    {
        string numStr = to_string(num);
        
        for (char letter : numStr)
        {
            if (letter == '7')
                ++answer;
        }
    }
    
    return answer;
}