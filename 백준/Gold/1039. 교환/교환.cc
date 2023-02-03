#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

string N;
int K, len, maxNum;

void Solve()
{
	queue<string> q;
	q.push(N);
	int curCnt = 0;

	while (!q.empty() && curCnt < K)
	{
		int curQueueSize = q.size();
		set<string> check;

		for (int idx = 0; idx < curQueueSize; ++idx)
		{
			string curNum = q.front();
			q.pop();

			for (int digitA = 0; digitA < len - 1; ++digitA)
			{
				for (int digitB = digitA + 1; digitB < len; ++digitB)
				{
					if (digitA == 0 && curNum[digitB] == '0')
						continue;

					swap(curNum[digitA], curNum[digitB]);
					if (check.find(curNum) == check.end())
					{
						if (curCnt == K - 1 && maxNum < stoi(curNum))
							maxNum = stoi(curNum);
						q.push(curNum);
						check.insert(curNum);
					}
					swap(curNum[digitA], curNum[digitB]);
				}
			}
		}
		++curCnt;
	}

	if (curCnt < K)
		cout << -1 << endl;
	else
		cout << maxNum << endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	cin >> K;
	len = N.size();

	if (len == 1 || (len == 2 && stoi(N) % 10 == 0))
	{
		cout << -1 << endl;
		return 0;
	}

	Solve();

	return 0;
}