#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    // 1LL은 long long 타입의 정수 1로, 곱셈 시 int 오버플로를 방지하기 위해 사용
    for (int width = yellow; 1LL * width * width >= yellow; --width)
    {
        if (yellow % width > 0)
            continue;
        
        int height = yellow / width;
        
        int total = (width + 2) * (height + 2);
        int expectedBrown = total - yellow;
        
        if (brown == expectedBrown)
        {
            answer.push_back(width + 2);
            answer.push_back(height + 2);
            break;
        }
    }
    
    return answer;
}
