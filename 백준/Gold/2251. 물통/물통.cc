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

#define MAX 201

bool check[MAX][MAX][MAX];
bool answerCheck[MAX];

int A, B, C;
vector<int> answer;

void Solve(int a, int b, int c)
{
	if (check[a][b][c])
		return;

	if (a == 0)
	{
		if (!answerCheck[c])
			answer.push_back(c);
	}

	check[a][b][c] = true;

	// A와 B 사이 물 붓기
	if (a + b <= B)
		Solve(0, a + b, c);
	else
		Solve(a + b - B, B, c);

	if (a + b <= A)
		Solve(a + b, 0, c);
	else
		Solve(A, a + b - A, c);

	// A와 C 사이 물 붓기
	if (a + c <= C)
		Solve(0, b, a + c);
	else
		Solve(a + b - C, b, C);

	if (a + c <= A)
		Solve(a + c, b, 0);
	else
		Solve(A, b, a + c - A);
	
	// B와 C 사이 물 붓기
	if (b + c <= B)
		Solve(a, b + c, 0);
	else
		Solve(a, B, b + c - B);

	if (b + c <= C)
		Solve(a, 0, b + c);
	else
		Solve(a, b + c - C, C);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	
	cin >> A >> B >> C;

	Solve(0, 0, C);

	sort(answer.begin(), answer.end());

	for (int i = 0; i < answer.size(); ++i)
		cout << answer[i] << " ";

	return 0;
}