#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list, int n) {
    int answer = 0;
    
    for (int i = 0; i < num_list.size(); ++i)
    {
        int num = num_list[i];
        
        if (num == n)
        {
            answer = 1;
            break;
        }
    }
    
    return answer;
}