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

#define MAX 100001

int N, M;
int heights[MAX];
int orders[MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
		cin >> heights[i];

	for (int i = 0; i < M; ++i)
	{
		int start, end, change;
		cin >> start >> end >> change;

		orders[start] += change;
		orders[end + 1] -= change;
	}

	for (int i = 2; i <= N; ++i)
		orders[i] += orders[i - 1];

	for (int i = 1; i <= N; ++i)
	{
		heights[i] += orders[i];
        printf("%d ", heights[i]);
	}

	

    return 0;
}
