#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <deque>
#include <cmath>
#include <stack>
#include <cstring>
#include <typeinfo>
#include <iomanip>
#include <limits.h> 
// #include <map>
#pragma warning(disable:4996)

using namespace std;

#define MAX 10001

int N;
int startIdx, endIdx;
int nums[MAX];
bool visited[MAX];

int Jump()
{
	queue<pair<int, int>> q;
	q.push({ startIdx, 0 });
	visited[startIdx] = true;

	while(!q.empty())
	{
		int curIdx = q.front().first;
		int curTime = q.front().second;
		q.pop();

		if (curIdx == endIdx)
			return curTime;

		int curNum = nums[curIdx];

		for (int jump = curNum; curIdx + jump <= N; jump += curNum)
		{
			int nxtIdx = curIdx + jump;

			if (visited[nxtIdx] == false)
			{
				visited[nxtIdx] = true;
				q.push({ nxtIdx, curTime + 1 });
			}
		}

		for (int jump = (-curNum); curIdx + jump >= 1; jump -= curNum)
		{
			int nxtIdx = curIdx + jump;

			if (visited[nxtIdx] == false)
			{
				visited[nxtIdx] = true;
				q.push({ nxtIdx, curTime + 1 });
			}
		}
	}

	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);	

	cin >> N;

	for (int i = 1; i <= N; ++i)
		cin >> nums[i];

	cin >> startIdx >> endIdx;

	int answer = Jump();

	cout << answer << endl;
	
	return 0;
}
