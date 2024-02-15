#include <string>
#include <vector>

using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;
    
    for (int num = l; num <= r; ++num)
    {
        bool success = true;
        
        int tempNum = num;
        
        while(tempNum > 0 && success == true)
        {
            int r = tempNum % 10;
            tempNum /= 10;
            
            if (r != 0 && r != 5)
                success = false;
        }
        
        if (success)
            answer.push_back(num);
    }
    
    // 만약 문제의 조건을 충족하는 정수가 없을 경우, -1이 담긴 배열을 return한다.
    if (answer.size() == 0)
        return { -1 };
    
    return answer;
}