#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int n) {
    vector<int> answer;
    
    int isLenOdd = arr.size() % 2 == 1;
    
    for (int i = 0; i < arr.size(); ++i)
    {
        if ((isLenOdd && i % 2 == 0) || (isLenOdd == false && i % 2 == 1))
            answer.push_back(arr[i] + n);
        else
            answer.push_back(arr[i]);
            
    }
    
    return answer;
}