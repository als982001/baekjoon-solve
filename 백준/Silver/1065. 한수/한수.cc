	#include <iostream>
	#include <string>
	#include <vector>
	#include <algorithm>
	#include <queue>
	#include <map>
	#include <memory.h>
	#include <deque>
	#include <cmath>
	#include <stack>
	#include <cstring>
	#include <typeinfo>
	#include <iomanip>
	#include <limits.h> 
	#pragma warning(disable:4996)

	using namespace std;

	#define MAX 1000011

	bool Check(int num)
	{
		if (num < 100)
			return true;

		string strNum = to_string(num);

		for (int i = 0; i < strNum.size() - 2; ++i)
		{
			if (strNum[i] - strNum[i + 1] != strNum[i + 1] - strNum[i + 2])
				return false;
		}

		return true;		
	}

	int main()
	{
		ios_base::sync_with_stdio(false);
		std::cin.tie(NULL);
		std::cout.tie(NULL);

		int num, count = 0;
		cin >> num;

		for (int n = 1; n <= num; ++n)
		{
			if (Check(n))
				++count;
		}

		cout << count << endl;

		return 0;
	}