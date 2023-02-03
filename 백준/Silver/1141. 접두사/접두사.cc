#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define MAX 51
using namespace std;

int N, answer, wordsNum;
string tempStr;
bool check[MAX];
vector<string> words;

bool Compare(string a, string b)
{
	return a.size() < b.size();
}

void Solve()
{
	answer = N;

	for (int idx = 0; idx < words.size(); ++idx)
	{
		string curStr = words[idx];
		bool canPush = true;

		for (int targetIdx = idx + 1; targetIdx < words.size(); ++targetIdx)
		{
			string targetStr = words[targetIdx];

			// 접두사인지 파악
			if (targetStr.find(curStr) == 0)
			{
				--answer;
				break;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> tempStr;
		words.push_back(tempStr);
	}
	
	sort(words.begin(), words.end(), Compare);
	

	Solve();

	cout << answer << endl;

	return 0;
}
