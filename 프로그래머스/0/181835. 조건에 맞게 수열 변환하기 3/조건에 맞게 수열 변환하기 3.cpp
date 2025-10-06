#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer;
    
    bool isOdd = k % 2 != 0;
    
    for (int i = 0; i < arr.size(); ++i)
    {
        int num = arr[i];
        
        if (isOdd)
            answer.push_back(num * k);
        else
            answer.push_back(num + k);
    }
    
    return answer;
}