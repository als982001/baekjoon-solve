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

int T, N;
int sum;
int num;
vector<int> answer;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> T;

	while(T--)
	{
		cin >> N;

		sum = 0;

		for (int i = 0; i < N; ++i)
		{
			cin >> num;

			sum += num;
		}

		answer.push_back(sum);
	}

	for (int i = 0; i < answer.size(); ++i)
		cout << answer[i] << endl;
}
