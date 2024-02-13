#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    
    int onlyEvenNum = 0;    // 짝수만 이어 붙인 수
    int onlyOddNum = 0;     // 홀수만 이어 붙인 수
    
    for (int i = 0; i < num_list.size(); ++i)
    {
        int num = num_list[i];
        
        if (num % 2 == 0)
            onlyEvenNum = (onlyEvenNum * 10) + num;
        else
            onlyOddNum = (onlyOddNum * 10) + num;
    }
    
    answer = onlyEvenNum + onlyOddNum;
    
    return answer;
}