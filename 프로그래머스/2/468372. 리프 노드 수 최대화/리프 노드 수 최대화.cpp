#include <string>
#include <vector>

using namespace std;

long long 최대_분배도;
long long maxLeaveNodesNum;

void Dfs(long long 분배도, long long 부모_노드_수, long long 남은_분배_노드_수, long long leaveNodesNum)
{
    // 매번 도달할 때마다 최대 리프 노드 개수 갱신
    if (maxLeaveNodesNum < leaveNodesNum)
        maxLeaveNodesNum = leaveNodesNum;
    
    // 만약 더 이상 지을 분배 노드가 없거나 배치할 수 있는 부모 노드가 없으면 종료
    if (부모_노드_수 == 0 || 남은_분배_노드_수 == 0)
        return;
    
    // 이번 층을 자식 2개짜리 분배 노드로 채우는 경우
    if (분배도 * 2 <= 최대_분배도)
    {
        // 내가 가진 남은 분배 노드 수랑 현재 층에 있는 부모 노드 수 중 작은 만큼만 지을 수 있다.
        long long 가능한_노드_수 = min(부모_노드_수, 남은_분배_노드_수);
        
        // 자식이 2개라면 기존 리프 노드가 1개 사라지고 2개가 생기므로 순이익은 -1 + 2 = 1
        Dfs(분배도 * 2, 가능한_노드_수 * 2, 남은_분배_노드_수 - 가능한_노드_수, leaveNodesNum + 가능한_노드_수 * 1);
    }
    
    // 이번 층을 자식 3개짜리 분배 노드로 채우는 경우
    if (분배도 * 3 <= 최대_분배도)
    {
        // 내가 가진 남은 분배 노드 수랑 현재 층에 있는 부모 노드 수 중 작은 만큼만 지을 수 있다.
        long long 가능한_노드_수 = min(부모_노드_수, 남은_분배_노드_수);
        
        // 자식이 3개라면 기존 리프 노드가 1개 사라지고 3개 생기므로 순이익은 -1 + 3 = 2
        Dfs(분배도 * 3, 가능한_노드_수 * 3, 남은_분배_노드_수 - 가능한_노드_수, leaveNodesNum + 가능한_노드_수 * 2);
    }
}

int solution(int dist_limit, int split_limit) {
    최대_분배도 = split_limit;
    maxLeaveNodesNum = -1;
    
    Dfs(1, 1, dist_limit, 1);
    
    return maxLeaveNodesNum;
}