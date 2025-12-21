#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    int n = name.length();

    // 좌우 이동의 최댓값은 그냥 한 방향으로 쭉 가는 것 (길이 - 1)
    int min_move = n - 1;

    for (int i = 0; i < n; ++i) 
    {
        // 1. 상하 이동 (알파벳 변경) 계산
        // 'A'에서 정방향 vs 'Z'에서 역방향 중 작은 값 선택
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);

        // 2. 좌우 이동 (커서 이동) 계산 최적화
        // 현재 위치(i) 다음부터 연속된 A가 끝나는 지점(next)을 찾음
        int next = i + 1;
        while (next < n && name[next] == 'A')
            next++;

        // 경우의 수 3가지 중 최솟값 갱신
        // Case 1: 그냥 오른쪽으로 가기 (초기값 min_move)
        
        // Case 2: 오른쪽으로 갔다가(i) 다시 돌아와서(i) 뒤로 가기(n - next)
        // 식: i * 2 + (n - next)
        min_move = min(min_move, i * 2 + (n - next));
        
        // Case 3: 뒤로 먼저 갔다가(n - next) 다시 돌아와서(n - next) 오른쪽으로 가기(i)
        // 식: (n - next) * 2 + i
        min_move = min(min_move, (n - next) * 2 + i);
    }

    answer += min_move;
    return answer;
}