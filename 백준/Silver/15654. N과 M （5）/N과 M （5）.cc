#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int n, m;
vector<int> nums;
vector<int> arr;
map<int, bool> check;


void Solve(int idx)
{
    if (idx == m)
    {
        for (int i = 0; i < arr.size(); ++i)
            printf("%d ", arr[i]);
            
        printf("\n");
        return;
    }
    
    for (int i = 0; i < nums.size(); ++i)
    {
        int num = nums[i];
    
        if (check[num] == false)
        {
            check[num] = true;
            arr.push_back(num);
            
            Solve(idx + 1);
            
            arr.pop_back();
            check[num] = false;
        }
    }
}

int main() {
    cin >> n >> m;
    
    for (int i = 0; i < n; ++i)
    {
        int num;
        
        scanf("%d", &num);
        
        check[num] = false;
        nums.push_back(num);
    }
    
    sort(nums.begin(), nums.end());
    
    Solve(0);
    
    return 0;
    

}