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

#define CASE 3
#define MAX 500001

int N, M;
string strN;
bool broken[10];
map<char, bool> isBroken;

int Abs(int num)
{
	return num < 0 ? -num : num;
}

int Bigger()
{
	int changeCount = 0;

	for (int num = N; num < (N + 1) * 10 + 1; ++num)
	{
		string strNum = to_string(num);
		bool success = true;

		for (int i = 0; i < strNum.size(); ++i)
		{
			char n = strNum[i];

			if (isBroken[n] == true)
			{
				success = false;
				break;
			}
		}

		if (success)
			return num;

		++changeCount;
	}

	return -1;
}

int Smaller()
{
	for (int num = N; num >= 0; --num)
	{
		string strNum = to_string(num);
		bool success = true;

		for (int i = 0; i < strNum.size(); ++i)
		{
			char n = strNum[i];

			if (isBroken[n] == true)
			{
				success = false;
				break;
			}
		}

		if (success)
			return num;
	}

	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

	cin >> N;
	cin >> M;

	strN = to_string(N);

	for (int m = 0; m < M; ++m)
	{
		int brokenNum;
		cin >> brokenNum;

		broken[brokenNum] = true;

		isBroken[brokenNum + '0'] = true;
	}

	if (N == 100)
	{
		cout << 0 << endl;
		return 0;
	}

	int currentNum = 100;
	int answer = Abs(N - currentNum);

	int biggerNum = Bigger();
	int smallerNum = Smaller();
	
	if (biggerNum != -1)
	{
		string strBigger = to_string(biggerNum);

		int pushCount = strBigger.size() + (biggerNum - N);
		
		if (answer > pushCount)
			answer = pushCount;
	}
	
	if (smallerNum != -1)
	{
		string strSmaller = to_string(smallerNum);

		int pushCount = strSmaller.size() + (N - smallerNum);

		if (answer > pushCount)
			answer = pushCount;
	}

	cout << answer << endl;

	return 0;
}