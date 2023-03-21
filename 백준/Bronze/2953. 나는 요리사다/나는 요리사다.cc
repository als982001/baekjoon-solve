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

pair<int, int> winner = { -1, -1 };

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	for (int person = 1; person <= 5; ++person)
	{
		int totalScore = 0;
		int score;

		for (int i = 0; i < 4; ++i)	
		{
			cin >> score;
			totalScore += score;
		}

		if (winner.second < totalScore)
			winner = { person, totalScore };		
	}

	printf("%d %d \n", winner.first, winner.second);

    return 0;
}
