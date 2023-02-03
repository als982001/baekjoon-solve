#include <iostream>
using namespace std;

unsigned long long N, cnt = 9;
unsigned long long cur = 10, tmp, back;
bool decreasing;

unsigned long long arr[] = { 76543210,
86543210,
87543210,
87643210,
87653210,
87654210,
 87654310,
 87654320,
 87654321,
 96543210,
 97543210,
 97643210,
 97653210,
 97654210,
 97654310,
 97654320,
 97654321,
 98543210,
 98643210,
 98653210,
 98654210,
 98654310,
 98654320,
 98654321,
 98743210,
 98753210,
 98754210,
 98754310,
 98754320,
 98754321,
 98763210,
 98764210,
 98764310,
 98764320,
 98764321,
 98765210,
 98765310,
 98765320,
 98765321,
 98765410,
 98765420,
 98765421,
 98765430,
 98765431,
 98765432,
 876543210,
 976543210,
 986543210,
 987543210,
 987643210,
 987653210,
 987654210,
987654310,
987654320,
987654321,
9876543210 };

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	if (N <= 9)
	{
		cout << N << endl;
		return 0;
	}
	else if (N > 1022)
	{
		cout << -1 << endl;
		return 0;
	}
	else if (N > 966)
	{
		cout << arr[N - 967] << endl;
		return 0;
	}


	while (cnt < N)
	{
		tmp = cur++;
		decreasing = true;

		while (tmp > 0)
		{
			back = tmp % 10;
			tmp /= 10;

			if (tmp > 0 && back >= tmp % 10)
			{
				decreasing = false;
				break;
			}
		}

		if (decreasing)
			++cnt;

	}

	cout << cur - 1 << endl;


	return 0;
}
