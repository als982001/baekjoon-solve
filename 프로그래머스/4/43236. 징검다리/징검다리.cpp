#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    
    // 바위들을 위치 순으로 정렬
    sort(rocks.begin(), rocks.end());
    
    // 바위 사이의 거리를 저장해두는 배열
    vector<int> diffs;
    
    // 시작지점 ~ 첫 번째 돌 사이 거리
    diffs.push_back(rocks[0]);
    
    for (int i = 0; i < rocks.size() - 1; ++i)
        diffs.push_back(rocks[i + 1] - rocks[i]);
    
    // 마지막 돌 ~ 도착지점 사이 거리
    diffs.push_back(distance - rocks.back());
    
    // 이분 탐색
    int minValue = 1;
    int maxValue = distance;

    while(minValue <= maxValue)
    {
        // 현재 케이스의 간격 기준치. 즉 이 값보다는 커야함
        int curMaxDist = (minValue + maxValue) / 2;
        
        int removedRocksNum = 0; // 제거된 바위의 개수
        int accDist = 0;         // 누적 간격 거리
        
        for (int i = 0; i < diffs.size(); ++i)
        {
            // 만약 돌 제거했을 때, 현재 누적 간격이 기준치보다 작으면 제거
            if (accDist + diffs[i] < curMaxDist)
            {
                accDist += diffs[i];
                ++removedRocksNum; // 제거한 돌 개수 1 증가
            }
            else // 그렇지 않으면 다시 누적 간격 거리 초기화
                accDist = 0;
            
            // 만약 제거한 돌 개수가 n보다 많다면 얼리 리턴
            if (removedRocksNum > n)
                break;
        }
        
        // 만약 제거한 돌 개수가 n보다 많다면 기준치가 더 작아져야함.
        // 왜냐하면 돌을 덜 제거해야 하기 때문
        if (removedRocksNum > n)
            maxValue = curMaxDist - 1;
        else // 그렇지 않은 경우는 답 갱신 후 기준치 더 크게 설정
        {
            answer = max(answer, curMaxDist);
            minValue = curMaxDist + 1;
        }
    }
    
    return answer;
}