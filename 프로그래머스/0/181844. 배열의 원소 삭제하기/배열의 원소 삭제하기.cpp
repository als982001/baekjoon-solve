#include <string>
#include <vector>
#include <set>

using namespace std;

int FindIndex(vector<int> arr, int targetNum)
{
    int idx = -1;
    
    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[i] == targetNum)
        {
            idx = i;
            break;
        }
    }
    
    return idx;
}

vector<int> solution(vector<int> arr, vector<int> delete_list) {
    vector<int> answer;
    
    set<int> deleteTargetNums;
    
    for (int i = 0; i < delete_list.size(); ++i)
    {
        int num = delete_list[i];
        
        deleteTargetNums.insert(num);
    }
    
    for (int i = 0; i < arr.size(); ++i)
    {
        int num = arr[i];
        
        int shouldSave = deleteTargetNums.find(num) == deleteTargetNums.end();
        
        if (shouldSave)
            answer.push_back(num);
    }
    
    return answer;
}