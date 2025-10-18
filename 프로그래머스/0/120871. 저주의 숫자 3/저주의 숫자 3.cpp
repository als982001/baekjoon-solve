#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    for (int i = 0; i < n; ++i) {
        ++answer;  // 다음 후보
        
        // 후보가 3의 배수이거나 '3'을 포함하면 계속 건너뛰기
        while (answer % 3 == 0 || to_string(answer).find('3') != string::npos) {
            ++answer;
        }
    }
    return answer;
}