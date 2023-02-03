#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <memory.h>
#include <deque>
#include <cmath>
#include <stack>
#include <cstring>
#include <typeinfo>

using namespace std;

#define MAX 111

int kingR, kingC, stoneR, stoneC;
int N;
string d;
map<string, int> dirs;
int nr[8] = { 0, 0, -1, 1, 1, 1, -1, -1 };
int nc[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

bool IsIn(int r, int c)
{
	return 1 <= r && r <= 8 && 1 <= c && c <= 8;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	dirs["R"] = 0;
	dirs["L"] = 1;
	dirs["B"] = 2;
	dirs["T"] = 3;
	dirs["RT"] = 4;
	dirs["LT"] = 5;
	dirs["RB"] = 6;
	dirs["LB"] = 7;

	
	char kR, kC, sR, sC;

	cin >> kC >> kR;
	kingR = kR - '0';
	kingC = kC - 'A' + 1;

	cin >> sC >> sR;
	stoneR = sR - '0';
	stoneC = sC - 'A' + 1;

	cin >> N;
    
	for (int n = 0; n < N; ++n)
	{
		cin >> d;
		int dir = dirs[d];

		int nxtR = kingR + nr[dir];
		int nxtC = kingC + nc[dir];

		if (!IsIn(nxtR, nxtC))
			continue;

		if (nxtR == stoneR && nxtC == stoneC)
		{
			int nxtStoneR = stoneR + nr[dir];
			int nxtStoneC = stoneC + nc[dir];

			if (IsIn(nxtStoneR, nxtStoneC))
			{
				kingR = nxtR;
				kingC = nxtC;

				stoneR = nxtStoneR;
				stoneC = nxtStoneC;
			}
		}
		else
		{
			kingR = nxtR;
			kingC = nxtC;
		}
	}

	printf("%c%c\n%c%c", kingC + 'A' - 1, kingR + '0', stoneC + 'A' - 1, stoneR + '0');


	return 0;
}
