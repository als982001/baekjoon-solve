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
int n, m;
vector<int> answer;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	cin >> T;

	for (int t = 0; t < T; ++t)
	{
		cin >> n >> m;

		int count = 0;
		
		for (int a = 1; a < n; ++a)
		{
			for (int b = a + 1; b < n; ++b)
			{
				if (((a * a) + (b * b) + m) % (a * b) == 0)
					++count;
			}
		}

		answer.push_back(count);
	}

	for (auto ans : answer)
		cout << ans << endl;
	
	
    return 0;
}
