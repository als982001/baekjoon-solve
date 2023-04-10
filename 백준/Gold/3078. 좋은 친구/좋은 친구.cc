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

#define MAX 21

int N, K;
long long answer = 0;
queue<int> ranks[MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N >> K;

	for (int rank = 1; rank <= N; ++rank)
	{
		string name;
		cin >> name;

		int len = name.size();

		while(!ranks[len].empty())
		{
			if (rank - ranks[len].front() > K)
				ranks[len].pop();
			else
				break;
		}

		answer += ranks[len].size();
		ranks[len].push(rank);
	}

	cout << answer << endl;
	
    return 0;
}
