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

using namespace std;

int caseNum;
double price;
vector<double> answer;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> caseNum;

	while (caseNum--)
	{
		cin >> price;

		price *= 0.8;

		answer.push_back(price);
	}

	for (int i = 0; i < answer.size(); ++i)
		printf("$%.2lf\n", answer[i]);


	return 0;
}
