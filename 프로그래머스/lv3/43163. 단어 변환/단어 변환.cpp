#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

bool CanChange(string wordA, string wordB)
{
	int differentAlpNum = 0;

	for (int i = 0; i < wordA.size(); ++i)
	{
		if (wordA[i] != wordB[i])
		{
			++differentAlpNum;

			if (differentAlpNum > 1)
				return false;
		}
	}

	return true;
}

int solution(string begin, string target, vector<string> words)
{
	map<string, bool> checked;

	queue<pair<string, int>> q;
	q.push({ begin, 0 });
	checked[begin] = true;	

	while(!q.empty())
	{
		string curWord = q.front().first;
		int curTime = q.front().second;
		q.pop();

		if (curWord == target)
			return curTime;

		for (int i = 0; i < words.size(); ++i)
		{
			string nxtWord = words[i];

			if (checked[nxtWord] == true)
				continue;

			if (CanChange(curWord, nxtWord))
			{
				checked[nxtWord] = true;
				q.push({ nxtWord, curTime + 1 });
			}
		}
	}

	return 0;
}

/*
bool check[55];

bool CanChange(string cur, string word)
{
	int different = 0;

	for (int i = 0; i < cur.size(); ++i)
	{
		if (cur[i] != word[i])
		{
			++different;

			if (different > 1)
				return false;
		}
	}

	return true;
}

int solution(string begin, string target, vector<string> words)
{
	int answer = 0;

	queue<pair<string, int>> q;
	q.push({ begin, 0 });

	while (!q.empty())
	{
		string curWord = q.front().first;
		int curTime = q.front().second;
		q.pop();

		if (curWord == target)
		{
			answer = curTime;
			break;
		}

		for (int i = 0; i < words.size(); ++i)
		{
			string word = words[i];

			if (check[i])
				continue;

			if (CanChange(curWord, word))
			{
				check[i] = true;
				q.push({ word, curTime + 1 });
			}
		}
	}

	return answer;
}
*/