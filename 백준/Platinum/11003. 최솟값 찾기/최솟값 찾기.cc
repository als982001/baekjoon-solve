#include <iostream>
#include <string>
#include <sstream>
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
#include <map>
#pragma warning(disable:4996)

using namespace std;

#define MAX 5000001

int N, L;
vector<int> nums;
deque<pair<int, int>> dq;
vector<int> answer;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N >> L;

	for (int idx = 1; idx <= N; ++idx)
	{
		int num;
		cin >> num;

		nums.push_back(num);
	}	

	for (int i = 0; i < nums.size(); ++i)
	{
		int idx = i + 1;
		int num = nums[i];

		while(!dq.empty())
		{
			if (dq.front().first < idx - L + 1)
				dq.pop_front();
			else
				break;
		}

		while(!dq.empty())
		{
			if (dq.back().second > num)
				dq.pop_back();
			else
				break;
		}

		dq.push_back({ idx, num });

		answer.push_back(dq.front().second);
	}

	for (int i = 0; i < answer.size(); ++i)
		printf("%d ", answer[i]);
		
    return 0;
}
