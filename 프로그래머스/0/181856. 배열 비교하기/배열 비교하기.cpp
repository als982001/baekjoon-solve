#include <string>
#include <vector>

using namespace std;

int GetSum (vector<int> arr)
{
    int sum = 0;
    
    for (int i = 0; i < arr.size(); ++i)
        sum += arr[i];
    
    return sum;
}

int solution(vector<int> arr1, vector<int> arr2) {
    int answer = 0;
    
    if (arr1.size() > arr2.size())
        answer = 1;
    else if (arr1.size() < arr2.size())
        answer = -1;
    else
    {
        int arr1Sum = GetSum(arr1);
        int arr2Sum = GetSum(arr2);
        
        if (arr1Sum > arr2Sum)
            answer = 1;
        else if (arr1Sum < arr2Sum)
            answer = -1;
        else
            answer = 0;
    }
    
    return answer;
}