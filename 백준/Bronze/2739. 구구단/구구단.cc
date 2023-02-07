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

int N;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);	

	cin >> N;

	for (int i = 1; i <= 9; ++i)
		printf("%d * %d = %d \n", N, i, N * i);
	
	
	return 0;
}
