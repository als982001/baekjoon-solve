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

int N;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> N;

	for (int n = N; n >= 1; --n)
	{
		for (int star = 1; star <= n; ++star)
			cout << "*";
		cout << endl;
	}


	return 0;
}
