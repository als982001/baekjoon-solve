#include <iostream>
using namespace std;
int A, B;

int main()
{
	cin >> A >> B;

	int times = 1;
	int cur = 1;
	int cur_t = cur;
	int sum = 0;


	while (times <= 1000)
	{
		if (cur_t == 0)
			cur_t = ++cur;

		if (times < A)
		{
			++times;
			--cur_t;
			continue;
		}
		if (times > B)
			break;

		sum += cur;

		++times;
		--cur_t;
	}

	cout << sum << endl;
	return 0;
}