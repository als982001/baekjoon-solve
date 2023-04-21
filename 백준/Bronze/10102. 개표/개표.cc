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

int V;
int scoreA = 0, scoreB = 0;
string result;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	cin >> V;

	cin >> result;

	for (int v = 0; v < V; ++v)
	{
		if (result[v] == 'A')
			++scoreA;
		else	
			++scoreB;
	}

	if (scoreA > scoreB)
		cout << "A" << endl;
	else if (scoreA < scoreB)
		cout << "B" << endl;
	else
		cout << "Tie" << endl;
	
    return 0;
}
