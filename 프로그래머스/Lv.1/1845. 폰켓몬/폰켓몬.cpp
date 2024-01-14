#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    map<int, int> count;
    
    for (int i = 0; i < nums.size(); ++i)
    {
        int num = nums[i];
        
        if (count[num] == 0)
            ++answer;
        ++count[num];
    }
    
    return answer > nums.size() / 2 ? nums.size() / 2 : answer;
}