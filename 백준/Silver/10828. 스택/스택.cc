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

#define PUSH "push"
#define POP "pop"
#define TOP "top"
#define SIZE "size"
#define EMPTY "empty"

int N;
string input;
stack<int> stk;
vector<int> answer;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N;
	cin.ignore();

	for (int i = 0; i < N; ++i)
	{
		getline(cin, input);

		istringstream command(input);
		string cmd, strNum;
		
		command >> cmd >> strNum;

		if (cmd == PUSH)
		{
			int num = stoi(strNum);
			stk.push(num);
		}
		else if (cmd == POP)
		{
			int num;

			if (stk.empty())
				num = -1;
			else
			{
				num = stk.top();
				stk.pop();
			}

			answer.push_back(num);
		}
		else if (cmd == SIZE)
		{
			answer.push_back(stk.size());
		}
		else if (cmd == EMPTY)
		{
			int isEmpty = stk.empty() ? 1 : 0;
			answer.push_back(isEmpty);
		}
		else if (cmd == TOP)
		{
			int num = stk.empty() ? -1 : stk.top();
			answer.push_back(num);
		}
	}

	for (int i = 0; i < answer.size(); ++i)
		cout << answer[i] << endl;

    return 0;
}
