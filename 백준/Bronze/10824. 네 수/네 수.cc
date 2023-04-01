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

string A, B, C, D;
long long answer;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> A >> B >> C >> D;

	string strNum[2] = { A + B, C + D };
	
	answer = stoll(strNum[0]) + stoll(strNum[1]);

	cout << answer << endl;

    return 0;
}
