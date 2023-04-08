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
string num;
vector<string> answer;

bool IsEven(char n)
{
	return n == '0' || n == '2' || n == '4' || n == '6' || n == '8';
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N;
	cin.ignore();

	for (int i = 0; i < N; ++i)
	{
		getline(cin, num);

		bool isEven = IsEven(num.back());

		if (isEven == true)
			answer.push_back("even");
		else
			answer.push_back("odd");
	}

	for (auto ans : answer)
		cout << ans << endl;
	

    return 0;
}
