#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> todo_list, vector<bool> finished) {
    vector<string> answer;
    
    for (int i = 0; i < todo_list.size(); ++i)
    {
        bool isFinished = finished[i];
        string todo = todo_list[i];
        
        if (isFinished == false)
            answer.push_back(todo);
    }
    
    return answer;
}