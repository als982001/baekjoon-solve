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

string num;
vector<string> answer;

bool IsPalindrome(string n)
{
	int mid = n.size() / 2;

	for (int front = 0, back = n.size() - 1; front < mid; ++front, --back)
	{
		if (n[front] != n[back])
			return false;
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

	cin >> num;

	while (num != "0")
	{
		bool result = IsPalindrome(num);

		if (result == true)
			answer.push_back("yes");
		else
			answer.push_back("no");

		cin >> num;
	}

	for (int i = 0; i < answer.size(); ++i)
		cout << answer[i] << endl;

	return 0;
}