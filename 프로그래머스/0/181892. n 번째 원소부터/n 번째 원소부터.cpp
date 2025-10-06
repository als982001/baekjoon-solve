#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list, int n) {
    vector<int> answer;
    
    for (int i = n - 1; i < num_list.size(); ++i)
    {
        int num = num_list[i];
        
        answer.push_back(num);
    }
    
    return answer;
}