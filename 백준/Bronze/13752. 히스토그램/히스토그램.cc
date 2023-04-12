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
int len;
vector<int> lens;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N;

	for (int n = 0; n < N; ++n)
	{
		cin >> len;
		lens.push_back(len);
	}

	for (int i = 0; i < lens.size(); ++i)
	{
		int len = lens[i];

		for (int l = 0; l < len; ++l)
			cout << "=";
		cout << endl;
	}


    return 0;
}
