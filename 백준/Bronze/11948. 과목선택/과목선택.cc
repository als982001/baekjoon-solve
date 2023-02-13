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

#define MAX 100

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);	

	priority_queue<int> 물화생지;
	priority_queue<int> 역사지리2;
	int score;

	for (int i = 0; i < 4; ++i)
	{
		cin >> score;
		물화생지.push(score);
	}

	for (int i = 0; i < 2; ++i)
	{
		cin >> score;
		역사지리2.push(score);
	}
	
	int total = 0;

	for (int i = 0; i < 3; ++i)
	{
		total += 물화생지.top();
		물화생지.pop();
	}

	total += 역사지리2.top();

	cout << total << endl;
	
	return 0;
}
