#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> lines) {
    const int OFFSET = 100;     // -100 ~ 100
    int cnt[201] = {0};         // 정수 칸 [i, i+1) 를 i로 표현 (i = -100..99)

    // 각 선분 [a,b] 가 덮는 칸은 [a, b) 이므로 i<b 로 순회
    for (const auto& line : lines) 
    {
        int a = line[0], b = line[1];
        
        for (int i = a; i < b; ++i) 
            ++cnt[i + OFFSET];
    }

    int answer = 0;
    for (int i = -100; i < 100; ++i) 
    {
        if (cnt[i + OFFSET] >= 2) 
        {  
            // 두 개 이상 겹친 칸만 길이에 포함
            ++answer;
        }
    }
    return answer;
}