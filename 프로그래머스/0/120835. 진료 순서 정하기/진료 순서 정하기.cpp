#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(int a, int b)
{
    return a > b;
}

int FindIndex(vector<int> arr, int targetValue)
{
    int idx = -1;
    
    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[i] == targetValue)
        {
            idx = i ;
            break;
        }
    }
    
    return idx;
}

vector<int> solution(vector<int> emergency) {
    vector<int> answer(emergency.size(), 0);
    
    vector<int> sortedEmergency(emergency);
    
    sort(sortedEmergency.begin(), sortedEmergency.end(), Compare);
    
    for (int i = 0; i < sortedEmergency.size(); ++i)
    {
        int val = sortedEmergency[i];
        
        int answerIdx = FindIndex(emergency, val);
        
        answer[answerIdx] = i + 1;
    }
    
    
    
    return answer;
}