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

vector<string> answer;

bool Valid(int a, int b, int c)
{
	return a < b + c;
}

bool Equilateral(int a, int b, int c)
{
	return a == b && b == c;
}

bool Isosceles(int a, int b, int c)
{	
	return a == b || b == c || c == a;
}

bool Scalene(int a, int b, int c)
{
	return a != b && b != c && c != a;
}


int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int a, b, c;

	cin >> a >> b >> c;

	while(a != 0 && b != 0 && c != 0)
	{
		priority_queue<int> pq;
		pq.push(a);
		pq.push(b);
		pq.push(c);

		int sides[3];

		for (int i = 0; i < 3; ++i)
		{
			sides[i] = pq.top();
			pq.pop();
		}
		
		if (Valid(sides[0], sides[1], sides[2]) == false)
			answer.push_back("Invalid");
		else if (Equilateral(sides[0], sides[1], sides[2]))
			answer.push_back("Equilateral");
		else if (Isosceles(sides[0], sides[1], sides[2]))
			answer.push_back("Isosceles");
		else if (Scalene(sides[0], sides[1], sides[2]))
			answer.push_back("Scalene");

		cin >> a >> b >> c;
	}

	for (int i = 0; i < answer.size(); ++i)
		cout << answer[i] << endl;

    return 0;
}
