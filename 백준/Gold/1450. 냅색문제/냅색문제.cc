#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
// #include <map>
#include <memory.h>
#include <deque>
#include <cmath>
#include <stack>
#include <cstring>
#include <typeinfo>
#include <limits.h> 
#pragma warning(disable:4996)

using namespace std;

#define MAX 31

int N, capacity;
int answer;
int givenWeights[MAX];
vector<int> weights1;
vector<int> weights2;

void Check(int idx, int endIdx, int sum, vector<int>& weights)
{
	// 현재 무게가 용량을 초과한 경우
	if (sum > capacity)
		return;

	// 인덱스가 마지막 인덱스까지 도달했음에도 용량을 초과하지 않은 경우
	if (idx > endIdx)
	{
		weights.push_back(sum);		// 무게 기록
		return;
	}

	Check(idx + 1, endIdx, sum, weights);						// idx번 무게 포함 안 한 경우
	Check(idx + 1, endIdx, sum + givenWeights[idx], weights);	// idx번 무게 포함한 경우
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> N >> capacity;

	for (int i = 0; i < N; ++i)
		cin >> givenWeights[i];

	// 그냥 문제를 풀기에는 최대 2^30번으로, 시간이 너무 많이 걸린다.
	// 따라서 주어진 무게를 두 개로 나눈다.
	// 그리고 나눈 무게들 별로 구성할 수 있는 무게를 구한다.
	// 그리고 오름차순으로 정렬한다
	Check(0, N / 2, 0, weights1);
	sort(weights1.begin(), weights1.end());

	Check(N / 2 + 1, N - 1, 0, weights2);
	sort(weights2.begin(), weights2.end());

	// 그리고 weight1의 무게 별 weights2의 무게가 몇 개까지 가능한지 반복문 이용해 검사한다
	int idx2 = weights2.size() - 1;

	for (int idx1 = 0; idx1 < weights1.size(); ++idx1)
	{
		// weights1의 무게가 정혀졌을 때, 용량을 넘지 않을 때의 인덱스를 구함 (오름차순이라서 가능)
		while (idx2 >= 0 && weights1[idx1] + weights2[idx2] > capacity)
			--idx2;

		answer += (idx2 + 1);	// idx2는 인덱스이므로(인덱스 = 개수 - 1), +1을 해준다
	}

	cout << answer << endl;

	return 0;
}