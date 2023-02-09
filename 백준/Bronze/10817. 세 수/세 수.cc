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

#define MAX 51

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);	


	priority_queue<int> pq;
	
	for (int i = 0; i < 3; ++i)
	{
		int num;
		cin >> num;

		pq.push(num);
	}

	pq.pop();

	cout << pq.top() << endl;


	return 0;
}
