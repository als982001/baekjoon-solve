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

int T;
vector<pair<int, int>> dices;

string Case(int idx, int num)
{
	return "Case " + to_string(idx) + ": " + to_string(num);
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	cin >> T;

	for (int t = 0; t < T; ++t)
	{
		int num1, num2;
		cin >> num1 >> num2;

		dices.push_back({ t + 1, num1 + num2 });
	}

	for (int i = 0; i < dices.size(); ++i)
		cout << Case(dices[i].first, dices[i].second) << endl;
	
    return 0;
}
