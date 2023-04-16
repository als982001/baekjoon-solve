#include <vector>
using namespace std;

#define MAX 200001

bool typeCheck[MAX];
int typeCount = 0;
vector<int> pokemons[MAX];

int solution(vector<int> nums)
{
    int takeNum = nums.size() / 2;
    
    for (int n = 0; n < nums.size(); ++n)
    {
        int typeIdx = nums[n];
        
        if (typeCheck[typeIdx] == false)
        {
            typeCheck[typeIdx] = true;
            ++typeCount;
        }
        
        pokemons[typeIdx].push_back(n + 1);
    }
    
    if (typeCount > takeNum)
        return takeNum;
    else
        return typeCount;
}