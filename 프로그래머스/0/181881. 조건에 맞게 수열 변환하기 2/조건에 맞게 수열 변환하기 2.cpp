#include <string>
#include <vector>

using namespace std;

vector<int> MakeNewArray(vector<int> arr)
{
    vector<int> newArr(arr);
    
    for (int i = 0; i < arr.size(); ++i)
    {
        int num = arr[i];
        
        if (num >= 50 && num % 2 == 0)
            arr[i] = num / 2;
        else if (num < 50 && num % 2 == 1)
            arr[i] = (num * 2) + 1;
    }
    
    return arr;
}

bool CheckSameArray(vector<int> arr1, vector<int> arr2)
{
    bool isSame = true;
    
    for (int i = 0; i < arr1.size(); ++i)
    {
        if (arr1[i] != arr2[i])
        {
            isSame = false;
            break;
        }
    }
    
    return isSame;
}

int solution(vector<int> arr) {
    int answer = 0;
    
    bool isSame = false;
    
    while(isSame == false)
    {
        vector<int> newArr = MakeNewArray(arr);
        ++answer;
        
        isSame = CheckSameArray(arr, newArr);
        
        arr = newArr;
    }
    
    return answer - 1;
    
}