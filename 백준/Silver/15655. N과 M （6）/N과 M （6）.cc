#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int n, m;
vector<int> arr;
vector<int> nums;
map<int, bool> check;

void Solve(int idx, int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < arr.size(); ++i)
            printf("%d ", arr[i]);
        printf("\n");
        return;
    }
    
    for (int i = idx; i < nums.size(); ++i)
    {
        if (check[i] == false)
        {
            check[i] = true;
            arr.push_back(nums[i]);
            
            Solve(i + 1, cnt + 1);
            
            arr.pop_back();
            check[i] = false;
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
    
    Solve(0, 0);
    
    return 0;
    

}