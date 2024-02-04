#include <iostream>
using namespace std;
int arr[1001] = { 0, };

int find(int n)
{
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	if (arr[n] != 0)
		return arr[n];
	return arr[n] = (find(n - 1) + find(n - 2)) % 10007;
	
}

int main()
{
	int n;
	cin >> n;

	printf("%d\n", find(n));
	return 0;
}