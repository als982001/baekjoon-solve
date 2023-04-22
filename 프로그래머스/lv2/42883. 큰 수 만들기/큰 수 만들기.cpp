#include <string>
#include <vector>
#include <stack>

using namespace std;

int answerSize;
int removeCount = 0;
stack<char> stk;
stack<char> lastStk;

string solution(string number, int K) {
    string answer = "";
    
    answerSize = number.size() - K;
    
    for (int i = 0; i < number.size(); ++i)
    {
        char num = number[i];
        
        while(!stk.empty() && removeCount < K)
        {
            if (stk.top() < num)
            {
                stk.pop();
                ++removeCount;
            }
            else
                break;
        }
        
        stk.push(num);
    }
    
    while(stk.size() > answerSize)
        stk.pop();
    
    while(!stk.empty())
    {
        lastStk.push(stk.top());
        stk.pop();
    }
    
    while(!lastStk.empty())
    {
        answer += lastStk.top();
        lastStk.pop();
    }
    
    return answer;
}