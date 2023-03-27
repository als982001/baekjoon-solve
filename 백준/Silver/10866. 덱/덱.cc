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

#define PUSH_FRONT "push_front"
#define PUSH_BACK "push_back"
#define POP_FRONT "pop_front"
#define POP_BACK "pop_back"
#define SIZE "size"
#define EMPTY "empty"
#define FRONT "front"
#define BACK "back"

int N;
string input;
deque<int> dq;
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

		if (cmd == PUSH_FRONT)
		{
			int num = stoi(strNum);
			dq.push_front(num);
		}
		else if (cmd == PUSH_BACK)
		{
			int num = stoi(strNum);
			dq.push_back(num);
		}
		else if (cmd == POP_FRONT)
		{
			int num;

			if (dq.empty())
				num = -1;
			else
			{
				num = dq.front();
				dq.pop_front();
			}

			answer.push_back(num);
		}
		else if(cmd == POP_BACK)
		{
			int num;

			if (dq.empty())
				num = -1;
			else
			{
				num = dq.back();
				dq.pop_back();
			}

			answer.push_back(num);
		}
		else if (cmd == SIZE)
		{
			int size = dq.size();
			answer.push_back(size);
		}
		else if (cmd == EMPTY)
		{
			int isEmpty = dq.empty() ? 1 : 0;
			answer.push_back(isEmpty);
		}
		else if (cmd == FRONT)
		{
			int num = dq.empty() ? -1 : dq.front();
			answer.push_back(num);
		}
		else if (cmd == BACK)
		{
			int num = dq.empty() ? -1 : dq.back();
			answer.push_back(num);
		}
	}

	for (int i = 0; i < answer.size(); ++i)
		cout << answer[i] << endl;

    return 0;
}
