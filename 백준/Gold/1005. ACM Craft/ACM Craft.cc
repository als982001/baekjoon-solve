#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 1001
using namespace std;

int T, N, K, W, a, b;
vector<int> p[MAX];
vector<int> answer;
int total[MAX];
int times[MAX];
int before_num[MAX];	// before_num[n] : 건물 n을 짓기 전에 지어야 하는 건물들 수
queue<int> q;

void Solve()
{
	for (int i = 1; i <= N; ++i)
	{
		if (before_num[i] == 0)
		{
			total[i] = times[i];
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 0; i < p[cur].size(); ++i)
		{
			int nxt = p[cur][i];

			if (--before_num[nxt] == 0)
				q.push(nxt);

			total[nxt] = max(total[nxt], total[cur] + times[nxt]);
		}
	}

	answer.push_back(total[W]);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	while (T--)
	{
		cin >> N >> K;

		for (int i = 1; i <= N; ++i)
			cin >> times[i];

		for (int i = 0; i < K; ++i)
		{
			cin >> a >> b;
			p[a].push_back(b);
			before_num[b]++;
		}

		cin >> W;

		Solve();

		for (int i = 1; i <= N; ++i)
		{
			p[i].clear();
			total[i] = 0;
			times[i] = 0;
			before_num[i] = 0;
		}
	}

	for (int i = 0; i < answer.size(); ++i)
		cout << answer[i] << endl;

	return 0;
}