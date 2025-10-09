#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    for (int i = 0; i < arr.size(); ++i)
    {
        int num = arr[i];
        
        if ((num >= 50) && (num % 2 == 0))
            answer.push_back(num / 2);
        else if ((num < 50) && (num % 2 == 1))
            answer.push_back(num * 2);
        else
            answer.push_back(num);
            
    }
    
    return answer;
}