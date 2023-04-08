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

int N;
int answer = 0;
stack<int> stk;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int height;
		cin >> height;

		if (stk.empty())
			stk.push(height);
		else
		{
			while(!stk.empty())
			{
				if (stk.top() <= height)
					stk.pop();
				else
					break;
			}

			stk.push(height);
		}
	}	

	while(!stk.empty())
	{
		++answer;
		stk.pop();
	}


	cout << answer << endl;
	
    return 0;
}
