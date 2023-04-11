#include <iostream>
#include <string>
#include <sstream>
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
#include <map>
#pragma warning(disable:4996)

using namespace std;

#define MAX 31

int D, K;
int A, B;
int dpA[MAX];
int dpB[MAX];

void Init()
{
	dpA[1] = 1, dpB[1] = 0;
	dpA[2] = 0, dpB[2] = 1;

	for (int i = 3; i <= D; ++i)
	{
		dpA[i] = dpA[i - 1] + dpA[i - 2];
		dpB[i] = dpB[i - 1] + dpB[i - 2];
	}	
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> D >> K;

	Init();

	for (int a = 1; a <= K; ++a)
	{
		int b = K - (dpA[D] * a);
		
		if (b % dpB[D] == 0)
		{
			A = a;
			B = (b / dpB[D]);
			break;
		}
		
	}

	cout << A << endl << B << endl;

    return 0;
}
