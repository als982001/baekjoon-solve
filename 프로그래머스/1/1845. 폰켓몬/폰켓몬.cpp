#include <vector>
#include <set>

using namespace std;

int Min(int a, int b)
{
    return a < b ? a : b;
}

int solution(vector<int> nums)
{    
    int cnt = 0;
    set<int> s;
    
    for (int num : nums)
    {
        if (s.count(num) == 0)
        {
            s.insert(num);
            ++cnt;
        }
    }

    return Min(cnt, nums.size() / 2);
}