#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    
    int oddIdxesSum = 0;
    int evenIdxesSum = 0;
    
    for (int i = 0; i < num_list.size(); ++i)
    {
        if (i % 2 == 0)
            evenIdxesSum += num_list[i];
        else
            oddIdxesSum += num_list[i];
    }
    
    answer = max(evenIdxesSum, oddIdxesSum);
    
    return answer;
}