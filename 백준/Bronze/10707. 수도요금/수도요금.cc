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

int xCharge;
int yBasicCharge;
int yUpperlimit;
int yAdditionalCharge;
int usage;

int costX = 0;
int costY = 0;

int CostY() 
{
	if (yUpperlimit < usage)
		return yBasicCharge + ((usage - yUpperlimit) * yAdditionalCharge);
	else
		return yBasicCharge;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> xCharge;
	cin >> yBasicCharge;
	cin >> yUpperlimit;
	cin >> yAdditionalCharge;
	cin >> usage;

	costX = xCharge * usage;
	costY = CostY();

	cout << min(costX, costY) << endl;
	

    return 0;
}
