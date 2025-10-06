#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> arr) {
    int answer = 1;
    
    int len = arr.size();
    
    for (int a = 0; a < len && answer == 1; ++a)
    {
        for (int b = 0; b < len && answer == 1; ++b)
        {
            if (arr[a][b] != arr[b][a])
            {
                answer = 0;
                break;
            }
        }
    }
    
    return answer;
}