#include <string>
#include <vector>

using namespace std;

int CharToInt(char num)
{  
    return num - '0';
}

int solution(string num_str) {
    int answer = 0;
    
    for (int i = 0; i < num_str.size(); ++i)
    {
        int num = CharToInt(num_str[i]);
        
        answer += num;
    }
    
    return answer;
}