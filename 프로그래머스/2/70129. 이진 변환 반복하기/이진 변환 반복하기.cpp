#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string NumToBinary(int num)
{    
    string result = "";
    
    while(num > 0)
    {
        int 나머지 = num % 2;
        result += to_string(나머지);
        
        num /= 2;
    }
    
    reverse(result.begin(), result.end());
    
    return result;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    int cnt = 0;
    int zeroCnt = 0;
    
    while(s != "1")
    {
        string newStr = "";
    
        for (char letter : s)
        {
            if (letter == '1')
                newStr += letter;
            else
                ++zeroCnt;
        }
    
        int strLen = newStr.size();
        s = NumToBinary(strLen);
        
        ++cnt;
    }
    
    answer.push_back(cnt);
    answer.push_back(zeroCnt);

    return answer;
}