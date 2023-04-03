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

#define PAL 0
#define PSE_PAL 1
#define NO 2

int sentenceNum;
string sentence;
vector<int> answer;

int Check(int leftIdx, int rightIdx, bool isPseudoCheck)
{
	while(leftIdx <= rightIdx)
	{	
		if (sentence[leftIdx] != sentence[rightIdx])
		{	
			if (isPseudoCheck == true)
				return NO;

			int result = Check(leftIdx, rightIdx - 1, true);

			if (result == PAL)
				return PSE_PAL;

			result = Check(leftIdx + 1, rightIdx, true);

			if (result == PAL)
				return PSE_PAL;

			return NO;
		}

		++leftIdx;
		--rightIdx;
	}

	return PAL;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);


	cin >> sentenceNum;

	for (int i = 0; i < sentenceNum; ++i)
	{
		cin >> sentence;

		answer.push_back(Check(0, sentence.size() - 1, false));
	}

	for (int i = 0; i < answer.size(); ++i)
		cout << answer[i] << endl;


    return 0;
}
