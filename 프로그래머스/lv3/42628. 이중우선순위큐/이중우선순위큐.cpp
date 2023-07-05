#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    deque<int> dq;
    
    for (int i = 0; i < operations.size(); ++i)
    {
        istringstream operation(operations[i]);
        
        string cmd, val;
        operation >> cmd >> val;
        
        if (cmd == "I")
        {
            dq.push_back(stoi(val));   
            sort(dq.begin(), dq.end());
        }
        else if (val == "1")
        {
            if (dq.empty() == false)
                dq.pop_back();
        }
        else if (val == "-1")
        {
            if (dq.empty() == false)
                dq.pop_front();
        }
    }
    
    if (dq.empty())
        answer = { 0, 0 };
    else
    {
        answer.push_back(dq.back());
        answer.push_back(dq.front());
    }
    

    
    return answer;
}