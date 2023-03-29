#include <iostream>
using namespace std;
int arr[31] = { 0, };
int find(int n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return 0;
	if (n == 2)
		return 3;
	if (arr[n] != 0)
		return arr[n];
	int result = 3 * find(n - 2);
	for (int i = 3; i <= n; ++i)
	{
		if (i % 2 == 0)
			result += 2 * find(n - i);
	}
	return arr[n] = result;
	
}
int main()
{
	int n;
	cin >> n;
	cout << find(n) << endl;
	return 0;
}