#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> numlist) {
    vector<int> answer;
    
    for (int i = 0; i < numlist.size(); ++i)
    {
        int num = numlist[i];
        
        if (num % n == 0)
            answer.push_back(num);
    }
    
    return answer;
}