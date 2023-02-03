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
#include <iomanip>
#include <limits.h> 
#pragma warning(disable:4996)

using namespace std;

#define MAX 40

bool visited[MAX][MAX];

bool CanGo(int befR, int befC, int curR, int curC)
{
	int diffR = abs(befR - curR);
	int diffC = abs(befC - curC);

	if (diffR == 2 && diffC == 1)
		return true;
	if (diffR == 1 && diffC == 2)
		return true;

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
	
	char row, col;
	int befR, befC, curR, curC, startR, startC;
	bool success = true;

	cin >> col >> row;
	curR = row - '0';
	curC = col - 'A' + 1;
	startR = curR;
	startC = curC;

	visited[curR][curC] = true;
	befR = curR;
	befC = curC;

	for (int i = 1; i < 36; ++i)
	{
		cin >> col >> row;

		curR = row - '0';
		curC = col - 'A' + 1;

		if (CanGo(befR, befC, curR, curC) == true && visited[curR][curC] == false)
		{
			visited[curR][curC] = true;
			befR = curR;
			befC = curC;
		}
		else
			success = false;
		
	}

	if (success == false)
		cout << "Invalid" << endl;
	else
	{
		if (CanGo(curR, curC, startR, startC))
			cout << "Valid" << endl;
		else
			cout << "Invalid" << endl;
	}

	return 0;
}