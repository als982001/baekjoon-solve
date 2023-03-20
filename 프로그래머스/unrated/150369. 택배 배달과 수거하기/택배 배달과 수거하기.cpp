#include <string>
#include <vector>
#include <stack>

using namespace std;

// 주어진 정보에서 각 타임마다의 최대거리를 구하는 함수
vector<int> CheckDistances(int cap, vector<int> info)
{	
	// 스택을 이용하여 가장 먼 거리부터 구한다.
	stack<int> stk;

	vector<int> distances;	// 반환할 배열

	int curCap;				// 각 순간마다의 cap
	int maxDistance;		// 각 순간마다의 최대 거리

	// 1. 거리를 처음부터 탐색한다.
	for (int i = 0; i < info.size(); ++i)
	{	
		// i + 1 => 시작점에서 i번까지의 거리

		// 1-1. 만약 i번째에 배달/수거할 것이 있다면, 그 횟수만큼 거리를 스택에 push한다.
		// stk.top = n -> n이라는 거리에 상자가 있다는 뜻
		if (info[i] > 0)
		{
			while(info[i] > 0)
			{	
				stk.push(i + 1);
				--info[i];
			}
		}
	}

	curCap = cap;
	maxDistance = -1;
	
	// 스택에는 상자의 개수만큼 거리 정보가 담기는데
	// 스택이 비었다는 말은 모든 상자를 배달/수거했다는 뜻이다.
	// 그렇기 때문에 스택이 빌 때까지 반복한다.
	while(!stk.empty())
	{	
		int distance = stk.top();	// 현재 상자의 위치
		stk.pop();

		--curCap;	// 상자 하나 해결했기 때문에 1 감소

		// 만약 현재 상자의 거리가 기록된 거리보다 크다면 갱신한다.
		if (maxDistance < distance)
			maxDistance = distance;

		// 만약 허용치가 0이거나 상자가 없다면, 
		// 이번 순간의 최대 거리를 기록한다.
		if (curCap == 0 || stk.empty())
		{
			distances.push_back(maxDistance);

			curCap = cap;
			maxDistance = -1;
		}
	}
	
	return distances;
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups)
{
	long long answer = 0;

	// 1. cap을 꽉 채워서 배달/수거할 때의 최대 거리들을 구한다.
	vector<int> deliveryDistances = CheckDistances(cap, deliveries);
	vector<int> pickupDistances = CheckDistances(cap, pickups);

	// 2. 배달/수거를 공통적으로 할 수 있을 때까지의 최대 거리들의 합을 구한다.
	if (deliveryDistances.size() < pickupDistances.size())
	{
		int sameLastPoint = deliveryDistances.size();

		for (int i = 0; i < sameLastPoint; ++i)
			answer += max(deliveryDistances[i], pickupDistances[i]);

		// 2-1. 만약 배달/수거를 따로 더 해야한다면, 그 거리들만 따로 더해준다.
		for (int i = sameLastPoint; i < pickupDistances.size(); ++i)
			answer += pickupDistances[i];
	}
	else
	{
		int sameLastPoint = pickupDistances.size();

		for (int i = 0; i < sameLastPoint; ++i)
			answer += max(deliveryDistances[i], pickupDistances[i]);

		// 2-1. 만약 배달/수거를 따로 더 해야한다면, 그 거리들만 따로 더해준다.
		for (int i = sameLastPoint; i < deliveryDistances.size(); ++i)
			answer += deliveryDistances[i];
	}

	// 왕복이기 때문에 2를 곱해준다.(오고 가는 거)
	return answer * 2;
}