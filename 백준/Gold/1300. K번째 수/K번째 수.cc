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
#pragma warning(disable:4996)

using namespace std;

#define SIZE 1000111

long long N, K;

long long Min(long long a, long long b)
{
	return a < b ? a : b;
}

long long Count(long long mid)
{
	long long count = 0;

	for (long long r = 1; r <= N; ++r)
	{
		if (r > mid)
			break;
	
		count += Min(N, mid / r);
	}

	return count;
}

long long Solve()
{
	long long answer = 0;

	long long min = 1;
	long long max = N * N;

	while (min <= max)
	{
		long long mid = (min + max) / 2;

		long long count = Count(mid);

		if (count < K)
			min = mid + 1;
		else
		{
			answer = mid;
			max = mid - 1;
		}
	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> N;
	cin >> K;

	long long answer = Solve();

	cout << answer << endl;

	return 0;
}
