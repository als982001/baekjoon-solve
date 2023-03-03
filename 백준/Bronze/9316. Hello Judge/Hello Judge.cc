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

#define MAX 511

#define SENTENCE "Hello World, Judge ";

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);	
	
	int N;
	
	cin >> N;

	for (int n = 1; n <= N; ++n)
		cout << "Hello World, Judge " << n << "!" << endl;

	return 0;
}
