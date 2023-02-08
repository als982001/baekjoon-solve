#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int h[10];
bool check[10];
vector<int> v;

bool Check(int cnt)
{
	if (cnt == 7)
	{
		int sum = 0;

		for (int i = 0; i < v.size(); ++i)
			sum += v[i];

		if (sum == 100)
			return true;
		return false;
	}

	for (int i = 0; i < 9; ++i)
	{
		if (!check[i])
		{
			check[i] = true;
			v.push_back(h[i]);
			if (Check(cnt + 1))
				return true;
			v.pop_back();
			check[i] = false;
		}
	}
	return false;
}

int main()
{
	for (int i = 0; i < 9; ++i)
	{
		cin >> h[i];
	}

	Check(0);

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); ++i)
		printf("%d\n", v[i]);

	return 0;
}