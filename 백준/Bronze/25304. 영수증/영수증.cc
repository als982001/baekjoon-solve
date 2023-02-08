#include <iostream>
#include <string>
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
// #include <map>
#pragma warning(disable:4996)

using namespace std;

#define MAX 101

long long total;
long long sum;
int N;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);	

	cin >> total;

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		long long cost;
		int num;

		cin >> cost >> num;

		sum += (cost * num);
	}

	if (total == sum)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}
