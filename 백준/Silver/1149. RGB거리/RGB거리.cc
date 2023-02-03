#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int N;
int price[1001][3];
int record[1001][3];

int Min(int a, int b, int c)
{
	int m = min(b, c);
	if (a < m)
		return a;
	else
		return m;
}

int main()
{
	cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		scanf("%d %d %d", &price[i][0], &price[i][1], &price[i][2]);
	}

	record[1][0] = price[1][0];
	record[1][1] = price[1][1];
	record[1][2] = price[1][2];

	for (int i = 2; i <= N; ++i)
	{
		record[i][0] = min(record[i-1][1], record[i-1][2]) + price[i][0];
		record[i][1] = min(record[i-1][2], record[i-1][0]) + price[i][1];
		record[i][2] = min(record[i-1][0], record[i-1][1]) + price[i][2];
	}

	cout << Min(record[N][0], record[N][1], record[N][2]) << endl;

	return 0;
}