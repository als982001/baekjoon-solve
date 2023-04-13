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

#define MAX 101

int T;
vector<pair<int, int>> answers;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> T;
	
	for (int t = 0; t < T; ++t)
	{
		pair<int, int> answer = { 0, MAX };

		for (int i = 0; i < 7; ++i)
		{
			int num;
			cin >> num;

			if (num % 2 == 0)
			{
				answer.first += num;
				answer.second = min(answer.second, num);
			}
		}

		answers.push_back(answer);
	}

	for (auto answer : answers)
		printf("%d %d \n", answer.first, answer.second);
	
    return 0;
}
