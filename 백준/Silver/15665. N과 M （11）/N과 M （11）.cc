#include <iostream>
#include <vector>
#include<string>
#include <algorithm>
#include <map>
#define MAX 10

using namespace std;

int N, M;
vector<int> arr;
vector<int> nums;
map<string, bool> resultMemo;

string MakeResult()
{
    string result = to_string(arr[0]);
    
    for (int i = 1; i < arr.size(); ++i)
    {
        result = result + "-" + to_string(arr[i]);
    }
    
    return result;
}

void PrintArray()
{
    for (int i = 0; i < arr.size(); ++i)
    {
        printf("%d ", arr[i]);
    }
    
    printf("\n");
    
    return;
}

void Select(int cnt)
{
    if (cnt == M)
    {
        string result = MakeResult();
        
        if (resultMemo[result] == false)
        {
            resultMemo[result] = true;
            PrintArray();
        }
    
        return;
    }
    
    for (int i = 0; i < N; ++i)
    {
        arr.push_back(nums[i]);
        Select(cnt + 1);
        arr.pop_back();
    }
}


int main()
{
    scanf("%d %d", &N, &M);
    
    for (int i = 0; i < N; ++i)
    {
        int num;
        
        scanf("%d", &num);
        
        nums.push_back(num);
    }
    
    sort(nums.begin(), nums.end());
    
    Select(0);

    return 0;
}