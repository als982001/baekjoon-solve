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
        string cmd, num;
        
        operation >> cmd >> num;
        
        if (cmd == "I")
        {
            dq.push_back(stoi(num));
            sort(dq.begin(), dq.end());
        }
        else if (num == "1")
        {
            if (dq.empty() == false)
                dq.pop_back();
        }
        else if (num == "-1")
        {
            if (dq.empty() == false)
                dq.pop_front();
        }
    }
    
    if (dq.size() == 0)
        return { 0, 0 };
    else if (dq.size() == 1)
        return { dq.front(), dq.front() };
    else
        return { dq.back(), dq.front() };
}