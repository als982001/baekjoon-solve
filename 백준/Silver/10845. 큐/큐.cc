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
#define SIZE "size"
#define EMPTY "empty"
#define FRONT "front"
#define BACK "back"

int N;
string input;
queue<int> q;
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
			q.push(num);
		}
		else if (cmd == POP)
		{
			if (q.empty())
				answer.push_back(-1);
			else
			{
				int num = q.front();
				q.pop();

				answer.push_back(num);
			}
		}
		else if (cmd == SIZE)
		{
			answer.push_back(q.size());
		}
		else if (cmd == EMPTY)
		{
			int isEmpty = q.empty() ? 1 : 0;
			answer.push_back(isEmpty); 
		}
		else if (cmd == FRONT)
		{
			if (q.empty())
				answer.push_back(-1);
			else
				answer.push_back(q.front());
		}
		else if (cmd == BACK)
		{
			if (q.empty())
				answer.push_back(-1);
			else
				answer.push_back(q.back());
		}
	}

	for (int i = 0; i < answer.size(); ++i)
		cout << answer[i] << endl;

    return 0;
}
