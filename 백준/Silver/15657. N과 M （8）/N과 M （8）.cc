#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int n, m;
vector<int> arr;
vector<int> nums;

void PrintArray()
{
    for (int i = 0; i < arr.size(); ++i)
        printf("%d ", arr[i]);
    
    printf("\n");
    
    return;
}

void Solve(int idx)
{
    if (arr.size() == m)
    {
        PrintArray();
        return;
    }
    
    for (int i = idx; i < n; ++i)
    {
        arr.push_back(nums[i]);
        Solve(i);
        arr.pop_back();
    }
}

int main() {
    cin >> n >> m;
    
    for (int i = 0; i < n; ++i)
    {
        int num;
        
        scanf("%d", &num);
        
        nums.push_back(num);
    }
    
    sort(nums.begin(), nums.end());
    
    Solve(0);
    
    return 0;
}