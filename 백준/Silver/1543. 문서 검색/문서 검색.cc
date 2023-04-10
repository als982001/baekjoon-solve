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

string sentence;
string pattern;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int count = 0;

	getline(cin, sentence);
	getline(cin, pattern);

	int lastIdx = sentence.size() - pattern.size();

	for (int startIdx = 0; startIdx <= lastIdx; ++startIdx)
	{
		bool isSame = true;

		for (int sentIdx = startIdx, idx = 0; idx < pattern.size(); ++idx, ++sentIdx)
		{
			if (pattern[idx] != sentence[sentIdx])
			{
				isSame = false;
				// startIdx = sentIdx;
				break;
			}
		}

		if (isSame)
		{
			++count;
			startIdx += (pattern.size() - 1);
		}
	}

	cout << count << endl;

    return 0;
}
