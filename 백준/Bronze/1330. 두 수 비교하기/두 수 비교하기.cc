#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
// #include <map>
#include <memory.h>
#include <deque>
#include <cmath>
#include <stack>
#include <cstring>
#include <typeinfo>

using namespace std;

#define SIZE 21

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	/*
	vector<string> temps = {
		"[[0,1],[1,2],[1,4],[0,8],[8,7],[9,10],[9,11],[4,3],[6,5],[4,6],[8,9]]	",
		"[[0,1],[0,2],[1,3],[1,4],[2,5],[2,6],[3,7],[4,8],[6,9],[9,10]]	"
	};

	for (int i = 0; i < temps.size(); ++i)
	{
		string temp = temps[i];

		for (int t = 0; t < temp.size(); ++ t)
		{
			if (temp[t] == '[')
				cout << "{";
			else if (temp[t] == ']')
				cout << "}";
			else
				cout << temp[t];
		}
		cout << ",\n";
	}
	*/

	/*
	for (int i = 0; i < SIZE; ++i)
	{
		vector<int> answer = solution(gems[i]);

		cout << "Answer = ";

		cout << answer[0] << "  " << answer[1] << endl;

	}
	*/

	int a, b;
	cin >> a >> b;

	if (a > b)
		cout << ">" << endl;
	else if (a < b)
		cout << "<" << endl;
	else
		cout << "==" << endl;

	return 0;
}
