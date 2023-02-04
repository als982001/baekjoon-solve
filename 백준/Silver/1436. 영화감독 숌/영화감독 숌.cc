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
#include <iomanip>
#include <limits.h> 
#pragma warning(disable:4996)

using namespace std;

#define CASE 3

int N;

int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

	cin >> N;

	int num = 666;

	while (N > 0)
	{
		string strNum = to_string(num);

		if (strNum.find("666") != -1)
			--N;

		++num;
	}

	cout << num - 1 << endl;




	return 0;
}