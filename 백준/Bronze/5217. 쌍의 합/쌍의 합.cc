#include <iostream>
#include <vector>

using namespace std;
vector<int> nums;

void PrintAnswer(int num)
{
    vector<pair<int, int>> pairs;

    for (int a = 1, b = num - 1; a < b; ++a, --b)
        pairs.push_back(make_pair(a, b));   
    
    
    
    if (pairs.size() == 0)
    {
        printf("Pairs for %d:\n", num);
        return;
    }
    
    printf("Pairs for %d: ", num);
    
    for (int i = 0; i < pairs.size() - 1; ++i)
        printf("%d %d, ", pairs[i].first, pairs[i].second);
        
    printf("%d %d\n", pairs[pairs.size() - 1].first, pairs[pairs.size() - 1].second);
}

int main()
{
    int casesNum, num;
    
    scanf("%d", &casesNum);
    
    for (int i = 0; i < casesNum; ++i)
    {
        scanf("%d", &num);
        
        nums.push_back(num);
    }
    
    for (int i = 0; i < nums.size(); ++i)
        PrintAnswer(nums[i]);

    return 0;
}