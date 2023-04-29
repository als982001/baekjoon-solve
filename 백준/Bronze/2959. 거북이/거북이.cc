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

int len;
int maxLen, minLen;
priority_queue<int> pq;

int main()
{
	ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
	std::cout.tie(NULL);

	for (int i = 0; i < 4; ++i)
	{
		cin >> len;
		pq.push(len);
	}


	pq.pop();
	maxLen = pq.top();
	pq.pop();
	pq.pop();
	minLen = pq.top();
	pq.pop();

	cout << maxLen * minLen << endl;

}
