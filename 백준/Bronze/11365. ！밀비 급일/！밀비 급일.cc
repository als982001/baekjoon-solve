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

string password;
vector<string> answer;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	getline(cin, password);

	while(password != "END") {
		reverse(password.begin(), password.end());
		answer.push_back(password);

		getline(cin, password);

	}

	for (int i = 0; i < answer.size(); ++i)
		cout << answer[i] << endl;
	
    return 0;
}
