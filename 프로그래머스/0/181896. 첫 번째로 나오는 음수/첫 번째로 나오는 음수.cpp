#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = -1;
    
    for (int i = 0; i < num_list.size(); ++i)
    {
        int num = num_list[i];
        
        if (num < 0)
        {
            answer = i;
            break;
        }
    }
    
    return answer;
}