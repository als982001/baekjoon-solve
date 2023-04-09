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

int num;
string order;
priority_queue<int> pq;
map<char, int> nums;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	for (int i = 0; i < 3; ++i)
	{
		cin >> num;
		cin.ignore();
		
		pq.push(num);
	}

	nums['C'] = pq.top();
	pq.pop();

	nums['B'] = pq.top();
	pq.pop();

	nums['A'] = pq.top();
	pq.pop();
	
	getline(cin, order);

	for (int i = 0; i < order.size(); ++i)
		printf("%d ", nums[order[i]]);

    return 0;
}
