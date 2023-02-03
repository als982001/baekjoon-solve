#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
// #include <map>
#include <memory.h>
#include <deque>
#include <cmath>
#include <stack>
#include <cstring>
#include <typeinfo>

using namespace std;

#define MAX 101

int N;
int A[MAX];
int B[MAX];

bool Compare(int a, int b)
{
	if (a > b)
		return true;
	else
		return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> A[i];

	for (int i = 0; i < N; ++i)
		cin >> B[i];

	sort(A, A + N);
	sort(B, B + N, Compare);

	int answer = 0;

	for (int i = 0; i < N; ++i)
		answer += (A[i] * B[i]);

	cout << answer << endl;

	return 0;
}
