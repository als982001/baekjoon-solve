#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer(2, 0);
    
    for (int num : num_list)
    {
        if (num % 2 == 0)
            answer[0] += 1;
        else
            answer[1] += 1;
    }
    
    return answer;
}