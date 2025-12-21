#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    vector<char> stk;
    
    for (int i = 0; i < number.size(); ++i)
    {
        char num = number[i];
        
        while(!stk.empty() && k > 0)
        {
            if (stk.back() < num)
            {
                stk.pop_back();
                --k;
            }
            else
                break;
        }
        
        stk.push_back(num);
    }
    
    for (char num : stk)
        answer += num;
    
    while(k > 0)
    {
        answer.pop_back();
        --k;
    }
    
    
    return answer;
}

