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

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool answer;
long long N;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N;

	while(N > 1)
	{
		if (N % 2 == 1)
		{
			cout << 0 << endl;
			return 0;
		}

		N /= 2;
	}

	cout << 1 << endl;

    return 0;
}
