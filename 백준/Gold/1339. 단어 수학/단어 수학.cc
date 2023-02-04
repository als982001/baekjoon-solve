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
#define ALP 27
#define TEN 10

int answer = 0;
int wordNum, alpNum;
string word;
int values[ALP];
vector<int> alps;

bool Bigger(int a, int b)
{
	if (a > b)
		return true;
	else
		return false;
}

int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

	cin >> wordNum;

	for (int w = 0; w < wordNum; ++w)
	{
		cin >> word;

		int mul = 1;

		for (int i = word.size() - 1; i >= 0; --i)
		{
			char alp = word[i];
			int alpIdx = alp - 'A';

			if (values[alpIdx] == 0)
				++alpNum;

			values[alpIdx] += mul;
			mul *= TEN;
		}
	}

	sort(values, values + ALP, Bigger);


	int mul = 9;

	for (int a = 0; a < alpNum; ++a)
	{
		answer += (values[a] * mul);
		--mul;
	}

	cout << answer << endl;

	return 0;
}