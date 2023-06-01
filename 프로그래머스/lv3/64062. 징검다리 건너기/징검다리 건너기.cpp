#include <string>
#include <vector>
#include <queue>
using namespace std;

/*

2   0
4   1
5   2   => 5
3   3   => 5
2   4   => 5
1   5   => 3
4   6   => 4
2   7   => 4
5   8   => 5
1   9   => 5

*/

int solution(vector<int> stones, int k) {
    int answer = 200111111;
    
    deque<pair<int, int>> dq;
    
    for (int idx = 0; idx < stones.size(); ++idx)
    {
        int stone = stones[idx];
        
        while(dq.empty() == false && dq.front().second <= idx - k)
            dq.pop_front();
        
        while(dq.empty() == false && dq.back().first < stone)
            dq.pop_back();
        
        dq.push_back({ stone, idx });
        
        if (idx >= k - 1 && answer > dq.front().first)
            answer = dq.front().first;
    }
    

    return answer;
}

/*
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define INF 987654321

int solution(vector<int> stones, int k) 
{
	int answer = INF;
    
    // k 구간에 따른 돌의 크기를 비교해 저장하는 deque
	// first: 각 돌들의 숫자
	// second: 각 돌들의 index
	deque<pair<int, int>> dq;

	for (int stoneIdx = 0; stoneIdx < stones.size(); ++stoneIdx)
	{
		// 1. 만약 deque에서 돌의 index가 주어진 k의 범위를 벗어나는 것이 있다면 모두 빼낸다.
		while(!dq.empty() && dq.front().second < stoneIdx - k + 1)
			dq.pop_front();
		// 이로서 반복문의 돌의 index(stoneIdx) 기준으로 k 범위 안의 돌들만 존재하게 된다.

		// 2. 만약 deque에서 돌의 숫자가 현재 돌보다 작은 거는 모두 빼낸다,
		while(!dq.empty() && dq.back().first < stones[stoneIdx])
			dq.pop_back();
		// 이로서 현재 돌 기준으로, 현재 돌 숫자보다 큰 돌들만 남게 된다.

		// 이는 건널 수 있는 횟수가 구간 k 안에서 가장 큰 돌에 따라 달라지기 때문인데,
		// 만약 구간 k에서 가장 큰 숫자가 3이라면 그 구간은 3번 건널 수 있기 때문이다.
		// 극단적인 예로, k가 3일 떄 [1, 3, 1] 이라는 구간이 있다면
		// [1, 3, 1], [ 0, 2, 0], [0, 1, 0], [0, 0, 0]으로 3번 건널 수 있다.
		
		// 3. 핸재 돌 정보를 push_back한다.
		// 만약 현재 돌을 써먹지 못한다면, 다음 반복문 때 pop 될 것이기 때문이다.
		dq.push_back({ stones[stoneIdx], stoneIdx });

		// 4. 만약 현재 검사하는 돌이 k보다 멀리 있으면서 (돌의 인덱스는 0부터 시작한다)
		// answer보다 크다면 답을 기록한다.
		// k보다 멀리 있어야 하는 이유는, 만약 전체 다리 길이가 k보다 작다면, 그냥 뛰어 넘어가면 되기 때문이다.
		if (stoneIdx >= k - 1 && dq.front().first < answer)
			answer = dq.front().first;
	}

	return answer;   
}
*/