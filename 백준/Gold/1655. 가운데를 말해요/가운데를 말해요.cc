#include <iostream>
#include <queue>

using namespace std;
#define endl "\n"
#define MAX 100001

int N;
int numList[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	
	vector<int> answer;

	cin >> N;

	for (int n = 0; n < N; ++n)
		cin >> numList[n];

	priority_queue<int> maxPQ, minPQ;

	for (int n = 0; n < N; ++n)
	{
		if (maxPQ.size() > minPQ.size())
			minPQ.push(-numList[n]);
		else
			maxPQ.push(numList[n]);

		if (maxPQ.empty() == false && minPQ.empty() == false)
		{
			if (maxPQ.top() > -minPQ.top())
			{
				int bigger = maxPQ.top();
				int smaller = -minPQ.top();

				maxPQ.pop();
				minPQ.pop();

				maxPQ.push(smaller);
				minPQ.push(-bigger);
			}
		}

		cout << maxPQ.top() << endl;
	}

	return 0;
}

