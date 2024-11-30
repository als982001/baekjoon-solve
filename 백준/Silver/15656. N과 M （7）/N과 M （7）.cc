#include <iostream>
#include <vector>
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

void Solve(int idx, int cnt)
{
    if (cnt == m)
    {
        PrintArray();
        return;
    }
    
    for (int i = 0; i < nums.size(); ++i)
    {
        arr.push_back(nums[i]);
        Solve(i + 1, cnt + 1);
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
    
    Solve(0, 0);
    
    return 0;
}