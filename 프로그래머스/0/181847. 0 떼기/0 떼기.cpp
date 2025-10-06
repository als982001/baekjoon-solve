#include <string>
#include <vector>

using namespace std;

string solution(string n_str) {
    string answer = "";
    
    bool isFirstZeros = true;
    
    for (int i = 0; i < n_str.size(); ++i)
    {
        char num = n_str[i];
        
        if (num == '0' && isFirstZeros)
        {
            
        }
        else
        {
            if (isFirstZeros)
                isFirstZeros = false;
            
            answer += num;
        }
    }
    
    return answer;
}