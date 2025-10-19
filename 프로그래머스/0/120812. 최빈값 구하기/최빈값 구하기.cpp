#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    
    int maxRecNum = -987654321;
    bool 최빈값여러개 = false;
    
    vector<int> nums;
    
    map<int, int> record;
    
    for (auto num : array)
    {
        if (record[num] == 0)
            nums.push_back(num);
        
        record[num] = record[num] + 1;
    }
    
    for (int num : nums)
    {
        int recNum = record[num];
        
        if (maxRecNum < recNum)
        {
            maxRecNum = recNum;
            answer = num;
            
            최빈값여러개 = false;
        }
        else if (maxRecNum == recNum)
        {
            최빈값여러개 = true;
            answer = -1;
        }
    }
    
    return answer;
}