#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <deque>
#include <cmath>
#include <stack>
#include <cstring>
#include <typeinfo>
#include <iomanip>
#include <limits.h> 
// #include <map>
#pragma warning(disable:4996)

using namespace std;

#define MAX 1001

// canWin의 예
// canWin[3] = 1 -> 만약 현재 돌의 개수가 3개일 경우, 현재 돌 가져갈 사람이 이길 수 있다.
// canWin[2] = 0 -> 약 현재 돌의 개수가 2개일 경우, 현재 돌 가져갈 사람은 진다.

int N;
int canWin[MAX];
string playerNames[2] = { "CY", "SK" };

int Battle(int stoneNum)
{	
	// 만약 현재 돌의 개수에 따른 결과를 알고 있다면 그 결과를 반환한다.
	if (canWin[stoneNum] >= 0)
		return canWin[stoneNum];

	int& result = canWin[stoneNum];

	int nextPlayerResult = Battle(stoneNum - 1) && Battle(stoneNum - 3) && Battle(stoneNum - 4);

	if (nextPlayerResult == 1)
		result = 0;
	else	
		result = 1;

	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);	
	
	memset(canWin, -1, sizeof(canWin));

	canWin[1] = 1;
	canWin[2] = 0;
	canWin[3] = 1;
	canWin[4] = 1;

	cin >> N;

	int winner  = Battle(N);

	cout << playerNames[winner] << endl;

	return 0;
}
