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

#define LEN 4

int numA, rowA, colA;
int numB, rowB, colB;
int sum = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	cin >> numA >> numB;

	numA -= 1;
	rowA = numA / LEN;
	colA = numA % LEN;

	numB -= 1;
	rowB = numB / LEN;
	colB = numB % LEN;

	sum = abs(rowA - rowB) + abs(colA - colB);

	cout << sum << endl;

    return 0;
}
